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

int fen[maxn];
int a[maxn];
vector <pair<int, int> > v;
queue <pair<int, int> > q;

void add(int ind, int val)
{
	ind++;
	while(ind < maxn)
	{
		fen[ind] += val;
		ind += ind & (-ind);
	}
}

int get(int ind)
{
	ind++;
	int res = 0;
	while(ind > 0)
	{
		res += fen[ind];
		ind -= ind & (-ind);
	}
	return res;
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
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0;
	for(auto u : v)
	{
		int val = u.first;
		int ind = u.second;
		while(q.size() && q.front().first > 2 * val)
		{
			add(q.front().second, 1);
			q.pop();
		}
		ans += get(ind);
		q.push(u);
	}
	cout << ans << endl;

    return 0;
}




























