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
    int mnq = atoi(argv[5]);
    int mxq = atoi(argv[6]);
    int mns = atoi(argv[7]);
    int mxs = atoi(argv[8]);
    int n = rnd.next(mnn, mxn);
    cout << n << endl;
    for(int i = 0; i < n - 1; i++)
    {
        cout << rnd.next(mna, mxa) << ' ';
    }
    cout << rnd.next(mna, mxa);
    cout << endl;
    int q = rnd.next(mnq, mxq);
    cout << q << endl;
    while(q--)
    {
        cout << rnd.next(mns, mxs) << endl;
    }

    return 0;
}









