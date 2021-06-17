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

string gens(int len, char c){
    string pattern = "[a-";
    pattern.push_back(c);
    pattern += "]{";
    pattern += str(len);
    pattern += "}";
    return rnd.next(pattern);
}

pair<string, string> genLCS(int n, int m, int c){
    string t = gens(m, c);
    int cnt = m-n;
    set<int> st;
    int tnc = cnt;
    bool f = 1;
    if(tnc > m / 2)
    {
        tnc = n;
        f = 0;
    }
    while(tnc--){
        while(true){
            int ind = rnd.next(m);
            if(st.count(ind))
                continue;
            st.insert(ind);
            break;
        }
    }
    string s;
    for(int i=0 ; i<m ; i++)
    {
        if(f && !st.count(i))
        {
            s.push_back(t[i]);
        }
        if(!f && st.count(i))
        {
            s.push_back(t[i]);
        }
    }
    return make_pair(t, s);
}

pair<string, string> genComplete(int n, int LCSSize, int r1, int l2)
{
    auto p = genLCS(LCSSize, n, r1);
    string lcs = p.second;
    string s1 = p.first;
    int n1 = s1.size();
    int n2 = rnd.next(LCSSize, n);
    while(n2 == 0)
    {
        n2 = rnd.next(LCSSize, n);
    }
    string s2 = "";
    for(int i = 0; i < n2; i++)
    {
        s2 += '-';
    }
    int p2 = 0;
    for(int i = 0; i < LCSSize; i++)
    {
        int idx = rnd.next(p2, n2 - LCSSize + i);
        p2 = idx + 1;
        s2[idx] = lcs[i];
    }
    for(int i = 0; i < n2; i++)
    {
        if(s2[i] == '-')
        {
            char cc = rnd.next(l2, 'z');
            s2[i] = cc;
        }
    }
    return make_pair(s1, s2);
}



int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int LCSSize = atoi(argv[2]);
    int mna = atoi(argv[3]);
    int mxa = atoi(argv[4]);
    int mnb = atoi(argv[5]);
    int mxb = atoi(argv[6]);
    char r1 = argv[7][0];
    char l2 = argv[7][1];
    auto p = genComplete(n, LCSSize, r1, l2);
    string s1 = p.first;
    string s2 = p.second;
    if(rnd.next(2))
    {
        swap(s1, s2);
    }
    cout << s1.size() << ' ' << s2.size() << ' ' << rnd.next(mna, mxa) << ' ' << rnd.next(mnb, mxb) << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}







