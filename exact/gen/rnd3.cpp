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

int32_t main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int a[200100];
    int mnn = atoi(argv[1]);
    int mxn = atoi(argv[2]);
    int mna = atoi(argv[3]);
    int mxa = atoi(argv[4]);
    int n = rnd.next(mnn, mxn);
    for(int i = 0; i < n; i++)
    {
        a[i] = rnd.next(mna, mxa);
    }
    int mn = 1e9 + 7;
    int mx = -mn;
    int l = 0;
    int r = n - 1;
    if(n > 10000)
    {
        l = 18;
        r = n - 57;
    }
    for(int i = l; i <= r; i++)
    {
        if(a[i] > mx)
        {
            mx = a[i];
        }
        if(a[i] < mn)
        {
            mn = a[i];
        }
    }
    int c = mx - mn;
    cout << n << ' ' << c << endl;
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
        if(i < n - 1)
        {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}









