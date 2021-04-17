#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100;

int cnt[N], who[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(who, -1, sizeof who);
    int n, m, k;cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;
        int &w = who[d/k];
        if(w == -1)
            w = d;
        cnt[d/k] ++;
    }
    cout << who[max_element(cnt, cnt+N) - cnt] << "\n";
}
