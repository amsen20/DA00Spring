#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 2e5+100;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int sz = atoi(argv[3]);
    cout << n << " " << m << " " << sz << "\n";
    for(int i=0 ; i<n ; i++)
        cout << rnd.next(m) << " \n"[i == n-1];
    return 0;
}
