//#pragma GCC optimize("Ofast")
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long
#define ld long double
#define pb push_back
//#define long long int
using namespace std;
const int maxn = 100100, maxm = 21, maxv = 100, mod = 1e9 + 7, maxa = 1005, maxs = 820, maxb = 10, base = 737, base2 = 3079, mod3 = 998244353, delt = 10513;
const long long inf = 2e16;
const int infint = 1e9 + 11;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

long double t[maxn];
long double w[maxn];
vector <pair<long double, int> > v;

int32_t main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
        v.push_back(make_pair((long double)(t[i] / w[i]), i));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int nt = 0;
    for(auto u : v)
    {
        nt += t[u.second];
        ans += nt * w[u.second];
    }
    cout << ans << endl;
    return 0;
}





