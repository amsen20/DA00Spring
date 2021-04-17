#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1, MAXN, "n");
    inf.readSpace();
    int m = inf.readInt(1, MAXM, "m");
    inf.readSpace();
    int k = inf.readInt(1, MAXM, "k");
    inf.readEoln();
    ensuref(m%k == 0, "m % k != 0.");
    for(int i=0 ; i<n ; i++){
        int d = inf.readInt(0, m-1);
        if(i < n-1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    inf.readEof();
}
