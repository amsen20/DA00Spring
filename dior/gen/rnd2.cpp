#include "testlib.h"
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
using namespace std;
int maxn = 100100;

void quick_sort(int b[], int l, int r)
{
    if(r - l < 1)
    {
        return ;
    }
    if(r - l == 1)
    {
        cout << b[l] << ' ';
        return ;
    }
    int p = rnd.next(l, r - 1);
    cout << b[p] << ' ';
    quick_sort(b, l, p);
    quick_sort(b, p + 1, r);
}

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int mnn = atoi(argv[1]);
    int mxn = atoi(argv[2]);
    int mna = atoi(argv[3]);
    int mxa = atoi(argv[4]);
    int n = rnd.next(mnn, mxn);
    int a[maxn];
    int b[maxn];
    map <int, bool> mp;
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        int x = rnd.next(mna, mxa);
        while(mp[x])
        {
            x = rnd.next(mna, mxa);
        }
        mp[x] = 1;
        a[i] = x;
        b[i] = a[i];
        cout << x << ' ';
    }
    cout << endl;
    sort(b, b + n);
    quick_sort(b, 0, n);
    cout << endl;
    return 0;
}









