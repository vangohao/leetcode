#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct A
    {
        int lc;
        int rc;
        string s;
    };
    vector<string> generateParenthesis(int n) {
        vector<A> * result = new vector<A>[2 * n + 1];
        result[0] = {{0,0,""}};
        for(int i = 0; i< 2 * n; ++i)
        {
            for(A a:result[i])
            {
                if(a.lc>a.rc)
                {
                    result[i+1].push_back({a.lc,a.rc+1,a.s+')'});
                }
                if(a.lc<n)
                {
                    result[i+1].push_back({a.lc+1,a.rc,a.s+'('});
                }
            }
        }
        vector<string> answer;
        for(A a:result[2*n])
        {
            answer.push_back(a.s);
        }
        return answer;
    }
};