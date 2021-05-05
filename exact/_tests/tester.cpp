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
using namespace std;

const int N = 2e5+100, M = 2e5+100;

int a[N];

int main(int argc, char * argv[])
{
    try{
        ifstream test_in(argv[1]);
        ifstream test_out(argv[2]);
        ifstream user_out(argv[3]);
        int n, c;
        test_in >> n >> c;
        for(int i=1 ; i<=n ; i++){
            test_in >> a[i];
        }
        int l1, r1, l2, r2;
        test_out >> l1;
        if(l1 == -1)
        {
            user_out >> l2;
            if(l2 == -1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        test_out >> r1;
        user_out >> l2 >> r2;
        int mn = 1e9 + 7;
        int mx = -mn;
        for(int i = l2; i <= r2; i++)
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
        int ans = mx - mn;
        if(ans == c)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }catch(string s){
        return 1;
    }

}
