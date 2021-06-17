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

const int MAXN = 2000, MAXM = 1e9;

string str(int n){
    string ret;
    while(n){
        int d = n%10;
        n /= 10;
        ret.push_back(d + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string get_pat(int len){
    string pattern = "[a-z]{";
    pattern += str(len);
    pattern += "}";
    return pattern;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    int n = inf.readInt(1, MAXN);
    inf.readSpace();
    int m = inf.readInt(1, MAXN);
    inf.readSpace();
    int a = inf.readInt(1, MAXM);
    inf.readSpace();
    int b = inf.readInt(1, MAXM);
    inf.readEoln();
    string s = inf.readToken(get_pat(n));
    inf.readEoln();
    string t = inf.readToken(get_pat(m));
    inf.readEoln();
    inf.readEof();
}