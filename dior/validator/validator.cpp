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

const int MAXN = 1e5, MAXM = 1e9;
int a[MAXN];
int pivot[MAXN];
int b[MAXN];
map <int, int> num;
int ind = 0;

void quick_sort(int l, int r)
{
    int p = pivot[ind];
    int id = num[p];
    if(r - l < 1)
    {
        return ;
    }
    ensuref(id >= l, "Heeey");
    ensuref(id < r, "Heeey");
    if(r - l <= 1)
    {
        return ;
    }
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


int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1 , MAXN);
    inf.readEoln();
    for(int i = 0; i < n; i++)
    {
        a[i] = inf.readInt(1, MAXM);
        b[i] = a[i];
        inf.readSpace();
    }
    sort(b, b + n);
    inf.readEoln();
    for(int i = 0; i < n; i++)
    {
        pivot[i] = inf.readInt(1, MAXM);
        num[b[i]] = i;
        inf.readSpace();
    }
    quick_sort(0, n);
    inf.readEoln();
    inf.readEof();
}










