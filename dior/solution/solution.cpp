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
const int maxn = 100100, maxm = 1530, mod = 1e9 + 7, maxa = 1005, maxs = 820, maxb = 12, base = 737, base2 = 3079, mod3 = 998244353, delt = 10513;
const long long inf = 1e17;
const int infint = 1e9 + 9;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

int a[maxn];
int b[maxn];
int pivot[maxn];
map <int, int> num;
int ind = 0;
int ans = 0;

void quick_sort(int l, int r)
{
    if(r - l <= 1)
    {
        return ;
    }
    ans += r - l - 1;
    int p = pivot[ind];
    int id = num[p];
    if(id - l >= 1)
    {
        ind++;
        quick_sort(l, id);

    }
    if(r - id - 1 >= 1)
    {
        ind++;
        quick_sort(id + 1, r);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++)
    {
        cin >> pivot[i];
        num[b[i]] = i;
    }
    quick_sort(0, n);
    cout << ans << endl;
    return 0;
}




















