#ifndef __GENTOOL_GRAPH_H__
#define __GENTOOL_GRAPH_H__

#define USE_TESTLIB
#ifdef USE_TESTLIB
#ifndef _TESTLIB_H_
#include "testlib.h"
#endif
#else
#include "rand.h"
#endif

#include "range.h"
#include<bits/stdc++.h>

using namespace std; // TODO erase it

/*
    * all edges struct must have v and u
*/
struct SimpleEdge{
    int v, u;
    SimpleEdge():
        v(-1), u(-1) {}
    
    SimpleEdge(int v, int u):
        v(v), u(u) {}
    
    SimpleEdge(const SimpleEdge& other){
        v = other.v;
        u = other.u;
    }
};

struct WeightedEdge{
    int v, u, w;
    static int minWeight, maxWeight; // [minWeight, maxWeight)
    WeightedEdge():
        v(-1), u(-1), w(-1) {}
    
    WeightedEdge(int v, int u):
        v(v), u(u) {
            w = rnd.next(maxWeight-minWeight) + minWeight;
        }
    
    WeightedEdge(int v, int u, int w):
        v(v), u(u), w(w) {}
    
    WeightedEdge(const WeightedEdge& other){
        v = other.v;
        u = other.u;
        w = other.w;
    }
};

int WeightedEdge::minWeight = 1;
int WeightedEdge::maxWeight = 1e9;

template<typename Ed>
Ed shift_up(const Ed &ed, int shift){
    Ed ret = Ed(ed);
    ret.v += shift;
    ret.u += shift;
    return ret;
}

template<typename Ed>
Ed transform(const Ed &ed, const vector<int> &p){
    Ed ret = Ed(ed);
    ret.v = p[ret.v];
    ret.u = p[ret.u];
    return ret;
}

void setWeightBound(int mn, int mx){
    WeightedEdge::minWeight = mn;
    WeightedEdge::maxWeight = mx;
}

template<typename Ed>
struct graph{

    typedef pair<int, Ed*> ie;

    int n, m;
    vector<vector<ie> > g; // TODO add matrix
    vector<set<int> > sg;
    /*
        * can be turned off
        * Store Edges Efficient
    */
    bool SEE = true;
    /*
        * can have Self Loop
    */
    bool SL = false;
    /*
        * can have Multiple Edges
    */
    bool ME = false;

    void build_sg(){
        assert(SEE);
        sg = vector<set<int> >(n, set<int>());
        for(int i=0 ; i<n ; i++){
            sg.push_back(set<int>());
            sg[i].clear();
            for(auto J : g[i]){
                int j = J.first;
                sg[i].insert(j);
            }
        }
    }

    void free_edges(){
        for(int i=0 ; i<n ; i++)
            for(auto U : g[i]){
                int u = U.first;
                if(i < u) // TODO take care of directed graphs
                    delete U.second;
            }
    }

    graph():
        n(-1), m(-1) {
            g = vector<vector<ie> >();
        }
    
    ~graph(){
        free_edges();
    }

    graph(int n):
        n(n){
            m = 0;
            g = vector<vector<ie> >(n, vector<ie>());
            sg = vector<set<int> >(n, set<int>());
        }

    graph(const graph &other){
        operator=(other);
    }

    graph<Ed>& operator = (const graph<Ed> &other){
        n = other.n;

        SEE = other.SEE; // TODO change to a sigle int32 conf
        SL = other.SL;
        ME = other.ME;

        // copying edges
        m = 0;
        free_edges();
        g = vector<vector<ie> >(n, vector<ie>());
        for(auto e : other.get_edges())
            if(
                !custom_add_edge(get<1>(e), get<2>(e), new Ed(*get<0>(e)))
            )
                throw "can't copy graphs.";
        return *this;
    }

    void extend(int new_n){
        if(new_n < n)
            throw "new graph's vertices size must be bigger than current size.";
        g.resize(new_n, vector<ie>());
        sg.resize(new_n, set<int>());
        n = new_n;
    }

    bool custom_add_edge(int v, int u, Ed *e){ // TODO take care of direcred graphs
        if(!SL && v == u)
            return false;
        if(SEE){
            if(!ME && (sg[v].count(u) || sg[u].count(v)))
                return false;
            sg[v].insert(u);
            sg[u].insert(v);
        }
        m ++;
        g[v].push_back(ie(u, e));
        g[u].push_back(ie(v, e));
        return true;
    }

    template<class ...Args>
    bool add_edge(int v, int u, Args ...args){
        return custom_add_edge(v, u, new Ed(v, u, args...));
    }

    vector<tuple<Ed*, int, int> > get_edges() const { // TODO take care of directed graphs
        set<tuple<Ed*, int, int> > st;
        for(int i=0 ; i<n ; i++)
            for(auto j : g[i]){
                auto cur = make_tuple(j.second, min(i, j.first), max(i, j.first));
                if(!st.count(cur))
                    st.insert(cur);
            }
        vector<tuple<Ed*, int, int> > ret;
        for(auto i : st)
            ret.push_back(i);
        return ret;
    }
};

// simple graph
typedef graph<SimpleEdge> SimpleGraph;
// weighted graph
typedef graph<WeightedEdge> WeightedGraph;

template<typename Ed>
Ed *default_edge_generator(int v, int u){
    return new Ed(v, u);
}

template<typename Ed>
bool addRandomEdge(
    graph<Ed> &gr,
    function<Ed*(int v, int u)> edge_generator=default_edge_generator<Ed>
    ){
    // TODO check if edges are a lot use another method
    int v, u;
    do{
        v = rnd.next(gr.n);
        u = rnd.next(gr.n);
    }while(!gr.custom_add_edge(v, u, edge_generator(v, u)));
    return true;
}

////////////////////////outputs////////////////////////

void print(const SimpleGraph& gr){
    // cout << gr.n << " " << gr.m << "\n";
    for(auto i : gr.get_edges())
        cout << get<0>(i)->v+1 << " " << get<0>(i)->u+1 << "\n";
}

void print(const WeightedGraph& gr){
    cout << gr.n << " " << gr.m << "\n";
   for(auto i : gr.get_edges())
        cout << get<0>(i)->v+1 << " " << get<0>(i)->u+1 << " " << get<0>(i)->w << "\n";
}

////////////////////////two graph operations////////////////////////

/*
    * not pure function
    * O(B.n + B.m) (*log(A))
*/
template<typename Ed>
bool concatGraphs(graph<Ed> &A, const graph<Ed> &B){
    // TODO check configs are same
    int offset = A.n;
    A.extend(A.n + B.n);
    for(auto e : B.get_edges())
        if(
            !A.custom_add_edge(get<1>(e) + offset, get<2>(e) + offset, new Ed( shift_up(*get<0>(e), offset) ))
        )
            return false;
    return true;
}

/*
    * pure function
    * O(A.n + A.m + B.n + B.m) (*log(A))
*/
template<typename Ed>
graph<Ed> concat_graphs(const graph<Ed> &A, const graph<Ed> &B){
    auto ret = graph<Ed>(0); // TODO take care of configs
    if(!concatGraphs(ret, A))
        throw "concat unsuccessful";
    if(!concatGraphs(ret, B))
        throw "concat unsuccessful";
    return ret;
}

/*
    * not pure function
    * O(B.n + B.m) (*log(A))
*/
template<typename Ed>
bool mergeGraphs(graph<Ed> &A, const graph<Ed> &B){
    // TODO check configs are same
    A.extend(max(A.n, B.n));
    for(auto e : B.get_edges())
        if(
            !A.custom_add_edge(get<1>(e), get<2>(e), new Ed(*get<0>(e)))
        )
            return false;
    return true;
}

/*
    * pure function
    * O(A.n + A.m + B.n + B.m) (*log(A))
*/
template<typename Ed>
graph<Ed> merge_graphs(const graph<Ed> &A, const graph<Ed> &B){
    auto ret = graph<Ed>(0); // TODO take care of configs
    if(!mergeGraphs(ret, A))
        throw "merge unsuccessful";
    if(!mergeGraphs(ret, B))
        throw "merge unsuccessful";
    return ret;
}

/*
    * mostly pure function (for gr)
    * O(gr.n + gr.m) (*log(gr))
*/
template<typename Ed>
graph<Ed> shuffle_graph(const graph<Ed> &gr, vector<int> &p){
    if(p.empty()){
        for(int i=0 ; i<gr.n ; i++)
            p.push_back(i);
        shuffle(p.begin(), p.end());
    }
    assert(gr.n == p.size());

    graph<Ed> ret(gr.n);
    for(auto e : gr.get_edges()){
        if(!
            ret.custom_add_edge(p[ get<1>(e) ], p[ get<2>(e) ], new Ed( transform( *get<0>(e), p ) ))
        )
            throw "shuffle unsuccessful";
    }

    return ret;
}

template<typename Ed>
graph<Ed> shuffle_graph(const graph<Ed> &gr){
    vector<int> p;
    return shuffle_graph(gr, p);
}

/*
    * same as above
    * not pure function
*/
template<typename Ed>
bool shuffleGraph(const graph<Ed> &gr){
    // TODO
}

////////////////////////custom graphs////////////////////////

/*
    * pure function
    * O(n) (or O(nlgn) if SSE)
    * t: how near to star should be tree. (100 star, -100 path)
*/
template<typename Ed>
graph<Ed> tree(
    vector<int> vertices,
    int t=0,
    function<Ed*(int v, int u)> edge_generator=default_edge_generator<Ed>
    // , TODO config
    ){
    auto ret = graph<Ed>(*max_element(vertices.begin(), vertices.end()) + 1);
    for(int i=1 ; i<ret.n ; i++){
        int to = rnd.wnext(i, t);
        int v = vertices[to], u = vertices[i];
        ret.custom_add_edge(v, u, edge_generator(v, u));
    }
    return ret;
}

template<typename Ed, class ...Args>
graph<Ed> add_tree(const graph<Ed> &gr, Args ...args){
    return merge_graphs(gr, tree<Ed>(rrange(gr.n), args...));
}

#endif