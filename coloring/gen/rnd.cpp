#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

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

string gens(int len, char c){
    string pattern = "[a-";
    pattern.push_back(c);
    pattern += "]{";
    pattern += str(len);
    pattern += "}";
    return rnd.next(pattern);
}

pair<string, string> genss(int n, int m, int c){
    string t = gens(m, c);
    int cnt = m-n;
    set<int> st;
    while(cnt --){
        while(true){
            int ind = rnd.next(m);
            if(st.count(ind))
                continue;
            st.insert(ind);
            break;
        }
    }
    string s;
    for(int i=0 ; i<m ; i++)
        if(!st.count(i))
            s.push_back(t[i]);
    return {s, t};
}

void gen_yes(int n, int m, char c){
    auto P = genss(n, m, c);
    cout << n << " " << m << "\n";
    cout << P.first << "\n" << P.second << "\n";
}

void gen_no(int n, int m, char c){
    auto P = genss(n, m, c);
    string s = P.first, t = P.second;
    // add noise to s
    int cnt = rnd.wnext(1, n, -1);
    while(cnt --){
        int ind = rnd.next(n);
        while(true){
            char ch = rnd.next('a', c);
            if(ch == s[ind])
                continue;
            s[ind] = ch;
            break;
        }
    }
    cout << n << " " << m << "\n";
    cout << s << "\n" << t << "\n";
}

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int t = atoi(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    char c = argv[4][0];
    cout << t << "\n";
    while(t --)
        if(rnd.next(2))
            gen_yes(n, m, c);
        else
            gen_no(n, m, c);
    return 0;
}