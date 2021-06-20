#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+100, MOD = 1e9+7;

typedef long long ll;

int add(ll a, int b){
    return (a + b + 2LL*MOD) % MOD;
}

int mul(ll a, int b){
    return a * b % MOD;
}

int bp(int a, int b){
    if(b == 0)
        return 1;
    int x = bp(a, b/2);
    x = mul(x, x);
    return b&1 ? mul(x, a) : x;
}

vector<int> g[N];
int c[N], n, m, C;

// graph:

int eval(int it){
    if(it == n)
        return 1;
    int ret=0;
    for(int i=0 ; i<C ; i++){
        bool f = true;
        for(auto u : g[it])
            if(c[u] == i){
                f = false;
                break;
            }
        if(f){
            c[it] = i;
            ret += eval(it+1);
            c[it] = -1;
        }
    }
    return ret;
}

void solve_g(){
    memset(c, -1, sizeof c);
    cout << eval(0) << "\n";
}

// bipartite:

vector<int> part[2];

void dfs_col(int v, int col){
    c[v] = col;
    part[col].push_back(v);
    for(auto u : g[v])
        if(c[u] == -1)
            dfs_col(u, 1-col);
}

int eval_2(int it){
    if(it == part[0].size()){
        int ret=1;
        for(auto v : part[1]){
            set<int> st;
            for(auto u : g[v])
                st.insert(c[u]);
            ret = mul(ret, C-st.size());
        }
        return ret;
    }
    int ret=0;
    for(int i=0 ; i<C ; i++){
        c[it] = i;
        ret = add(ret, eval_2(it+1));
    }
    return ret;
}

void solve_b(){
    memset(c, -1, sizeof c);
    for(int i=0 ; i<n ; i++)
        if(c[i] == -1)
            dfs_col(0, 0);
    cout << eval_2(0) << "\n";
}

// tree:

void solve_t(){
    cout << mul(C, bp(C-1, n-1)) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char t;cin >> t >> n >> C >> m;
    while(m --){
        int v, u;cin >> v >> u;v --;u --;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    switch (t){
    case 'g':
        solve_g();
        break;
    case 'b':
        solve_b();
        break;
    case 't':
        //solve_t();
        break;
    }
    return 0;
}