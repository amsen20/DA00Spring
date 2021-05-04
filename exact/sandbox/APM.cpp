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
using namespace std;
const int maxn = 200100;
const long long inf = 2e17;

map <int, int> is;
int a[maxn];

bool check(int l, int r, int c)
{
	int mid = (l + r) / 2;
	is.clear();
	int mn = inf;
	int mx = -inf;
	for(int i = mid; i < r; i++)
	{
		if(a[i] > mx)
		{
			mx = a[i];
			int tmp = a[i] - c;
			if(tmp < mn)
			{
				is[tmp] = i;
			}
		}
		if(a[i] < mn)
		{
			mn = a[i];
		}
	}
	mn = inf;
	mx = -inf;
	for(int i = mid - 1; i >= l; i--)
	{
		if(a[i] < mn)
		{
			mn = a[i];
			int tmp = a[i] + c;
			if(tmp > mx)
			{
				if(is[a[i]])
				{
					cout << i << ' ' << is[a[i]] << endl;
					return 1;
				}
			}
		}
		if(a[i] > mx)
		{
			mx = a[i];
		}
	}
	is.clear();
	mn = inf;
	mx = -inf;
	for(int i = mid - 1; i >= l; i--)
	{
		if(a[i] > mx)
		{
			mx = a[i];
			int tmp = a[i] - c;
			if(tmp < mn)
			{
				is[tmp] = i;
			}
		}
		if(a[i] < mn)
		{
			mn = a[i];
		}
	}
	mn = inf;
	mx = -inf;
	for(int i = mid; i < r; i++)
	{
		if(a[i] < mn)
		{
			mn = a[i];
			int tmp = a[i] + c;
			if(tmp > mx)
			{
				if(is[a[i]])
				{
					cout << is[a[i]] << ' ' << i << endl;
					return 1;
				}
			}
		}
		if(a[i] > mx)
		{
			mx = a[i];
		}
	}
	return 0;

}

bool solve(int l, int r, int c)
{
	if(r - l == 1)
	{
		if(c == 0)
		{
			cout << l << ' ' << r - 1 << endl;
			return 1;
		}
		return 0;
	}
	int mid = (l + r) / 2;
	if(solve(l, mid, c) || solve(mid, r, c) || check(l, r, c))
	{
		return 1;
	}
	return 0;
}


int32_t main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;

    for(int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    }

    if(!(solve(1, n + 1, c)))
    {
    	cout << -1 << endl;
    }

    return 0;
}




























