#include<bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;cin >> t;
    while(t --){
        int n, m;cin >> n >> m;
        string s, t;cin >> s >> t;
        int it = 0;
        for(auto c : t)
            if(it < n && s[it] == c)
                it ++;
        cout << (it>=n ? "YES" : "NO") << "\n";
    }
    return 0;
}