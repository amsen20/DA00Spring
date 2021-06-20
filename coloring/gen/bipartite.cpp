#include "testlib.h"
#include "graph.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int C = atoi(argv[2]);
    int m = atoi(argv[3]);
    assert(n%2 == 0);
    cout << "b " << n << " " << C << " " << m << "\n";
    auto g = SimpleGraph(n);
    while(m --){
        while(true){
            int v = rnd.next(n/2);
            int u = rnd.next(n/2, n-1);
            if(g.add_edge(v, u))
                break;
            
        }
    }
    shuffle_graph(g);
    print(g);
    return 0;
}