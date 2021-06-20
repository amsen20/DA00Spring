#ifndef __GENTOOL_RANGE_H__
#define __GENTOOL_RANGE_H__

#define USE_TESTLIB

#ifdef USE_TESTLIB
#ifndef _TESTLIB_H_
#include "testlib.h"
#endif
#else
#include "rand.h"
#endif

#include<bits/stdc++.h>

using namespace std; // TODO erase it

vector<int> range(int st, int en){ // [st, en)
    assert(en>st);
    vector<int> ret;
    for(int i=st ; i<en ; i++)
        ret.push_back(i);
    return ret;
}

vector<int> range(int en){ // [0, en)
    return range(0, en);
}

vector<int> rrange(int st, int en){ // random shuffled range
    auto ret = range(st, en);
    shuffle(ret.begin(), ret.end());
    return ret;
}

vector<int> rrange(int en){
    return rrange(0, en);
}

#endif