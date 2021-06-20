#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    char t = inf.readChar('g');
    inf.readSpace();
    int n = inf.readInt(2, 8);
    inf.readSpace();
    int C = inf.readInt(2, 8);
    inf.readSpace();
    int m = inf.readInt(1, n*(n-1)/2);
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
    }
    inf.readEof();
}