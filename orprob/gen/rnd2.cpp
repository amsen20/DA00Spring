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

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);

    int mnn = atoi(argv[1]);
    int mxn = atoi(argv[2]);
    int mna = atoi(argv[3]);
    int mxa = atoi(argv[4]);
    int n = rnd.next(mnn, mxn);
    cout << n << endl;
    int id1 = rnd.next(0, n - 3);
    int id2 = rnd.next(id1, n - 2);
    int sd = rnd.next(0, 100);
    if(sd & 1)
    {
        swap(id1, id2);
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(i == id1)
        {
            cout << (1 << mxa) + 1 << ' ';
            continue ; 
        }
        if(i == id2)
        {
            cout << (1 << mxa) + (1 << (mxa - 1)) << ' ';
            continue ;
        }
        cout << rnd.next(mna, mxa) << ' ';
    }
    cout << rnd.next(mna, mxa);
    cout << endl;
    return 0;
}









