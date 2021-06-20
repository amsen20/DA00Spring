#include "testlib.h"
#include "graph.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int C = atoi(argv[2]);
    int m = atoi(argv[3]);
    cout << "t " << n << " " << C << " " << m << "\n";
    print(add_tree(SimpleGraph(n)));
    return 0;
}