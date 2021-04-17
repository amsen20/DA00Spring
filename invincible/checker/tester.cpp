#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+100, M = 2e5+100;

int a[N];
vector<int> buck[M];

int main(int argc, char * argv[])
{
    try{
        ifstream test_in(argv[1]);
        ifstream test_out(argv[2]);
        ifstream user_out(argv[3]);
        int n, m, k;
        test_in >> n >> m >> k;
        for(int i=0 ; i<n ; i++){
            int d;test_in >> d;
            buck[d/k].push_back(d);
        }
        set<int> st;
        int mx=0;
        for(int i=0 ; i<M ; i++)
            mx = max(mx, (int)buck[i].size());
        for(int i=0 ; i<M ; i++)
            if(buck[i].size() == mx)
                for(auto j : buck[i])
                    st.insert(j);

        int out;user_out >> out;
        if(st.count(out))
            return 0;
        else
            return 1;
    }catch(string s){
        return 1;
    }

}
