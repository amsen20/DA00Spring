#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100;

int cnt[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;cin >> n >> m >> k;
    int mx = 1e9;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;
        cnt[d] ++;
    }
    cout << (max_element(cnt, cnt+N) - cnt) << "\n";
}
