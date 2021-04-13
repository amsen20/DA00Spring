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
//#define ll long long
//#define ll long long
//#define ld long double
//#define long long int
using namespace std;
const int maxn = 1000100, maxm = 1530, mod = 1e9 + 7, maxa = 1005, maxs = 820, maxb = 12, base = 737, base2 = 3079, mod3 = 998244353, delt = 10513;
const long long inf = 1e17;
const int infint = 1e9 + 9;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

int cnt[maxn];
int ps[maxn];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 0; i < maxn; i++)
    {
        ps[i] = sum;
        sum += cnt[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        cout << ps[a] << ' ' << cnt[a] << ' ' << sum - ps[a] - cnt[a] << endl;
    }

    return 0;
}




















