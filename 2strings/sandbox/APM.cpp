#include<bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;cin >> t;
    while(t --){
        int n, m;cin >> n >> m;
        string s, t;cin >> s >> t;
        bool f = false;
        for(int msk=0 ; msk<(1<<m) ; msk++){
            if(__builtin_popcount(msk) != n)
                continue;
            string cur;
            for(int i=0 ; i<m ; i++)
                if(msk & (1 << i))
                    cur.push_back(t[i]);
            if(cur == s){
                f = true;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << "\n";
    }
    return 0;
}