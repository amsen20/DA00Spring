#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5+100;

int par[N];

int root(int v){
    return par[v] = (par[v] == v ? v : root(par[v]));
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    char t = inf.readChar('t');
    inf.readSpace();
    int n = inf.readInt(2, N);
    for(int i=0 ; i<n ; i++)
        par[i] = i;
    inf.readSpace();
    int C = inf.readInt(2, N);
    inf.readSpace();
    int m = inf.readInt(n-1, n-1);
    inf.readEoln();
    set<ii> st;
    while(m --){
        int v = inf.readInt(1, n);v --;
        inf.readSpace();
        int u = inf.readInt(1, n);u --;
        inf.readEoln();
        ensuref(v != u, "Self loop!");
        int rv = root(v), ru = root(u);
        ensuref(rv != ru, "Loop!");
        par[rv] = ru;
        ensuref(!st.count(ii(v, u)) && !st.count(ii(u, v)), "Multiple edges!");
        st.insert(ii(v, u));
    }
    inf.readEof();
}