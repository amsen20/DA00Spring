#include <bits/stdc++.h>
/// this time?
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100;
ll c[N],W[N];
bool cmp(pii a,pii b){
    return a.F*b.S<a.S*b.F;
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int j=1;j<=n;j++) cin >> W[j];
    vector <pii> a;
    for (int i=1;i<=n;i++){
        a.pb({c[i],W[i]});
    }
    sort(a.begin(),a.end(),cmp);
    ll ans=0;
    ll t=0;
    for (auto u : a){
        t+=u.F;
        ans+=t*u.S;
    }
    kill(ans);
}

