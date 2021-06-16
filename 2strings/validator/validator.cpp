#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

string str(int n){
    string ret;
    while(n){
        int d = n%10;
        n /= 10;
        ret.push_back(d + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string get_pat(int len){
    string pattern = "[a-z]{";
    pattern += str(len);
    pattern += "}";
    return rnd.next(pattern);
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    int t = inf.readInt(1, 10);
    while(t--){
        int n = inf.readInt(1, MAXN);
        int m = inf.readInt(1, MAXN);
        ensuref(n <= m, "n should be less than m");
        string s = inf.readToken(get_pat(n));
        string t = inf.readToken(get_pat(m));
    }
}