#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5+100;

int c[N];
vector<int> g[N];

bool dfs_col(int v, int col){
    c[v] = col;
    bool f = true;
    for(auto u : g[v])
        if(c[u] == -1)
            f &= dfs_col(u, 1-col);
        else if(c[u] == col)
            return false;
    return true;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    char t = inf.readChar('g');
    inf.readSpace();
    int n = inf.readInt(2, 8);
    ensuref(n%2 == 0, "Odd n!");
    inf.readSpace();
    int C = inf.readInt(2, 8);
    inf.readSpace();
    int m = inf.readInt(1, n/2*n/2);
    inf.readEoln();
    set<ii> st;
    while(m --){
        int v = inf.readInt(1, n);
        inf.readSpace();
        int u = inf.readInt(1, n);
        inf.readEoln();
        ensuref(v != u, "Self loop!");
        ensuref(!st.count(ii(v, u)) && !st.count(ii(u, v)), "Multiple edges!");
        st.insert(ii(v, u));
        g[v].push_back(u);
        g[u].push_back(v);
    }
    inf.readEof();
    for(int i=0 ; i<n ; i++)
        if(c[i] == -1)
            ensuref(dfs_col(i, 0), "Odd loop!");
}