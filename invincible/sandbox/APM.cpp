#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100;

int cnt[N], who[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;cin >> n >> m >> k;
    int mn = 1e9;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;
        mn = min(mn, d);
    }
    cout << mn << "\n";
}
