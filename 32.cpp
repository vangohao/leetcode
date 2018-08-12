class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.length();
        vector<int> dp(l,l);
        stack<int> st;
        for(int i = 0; i<l; ++i)
        {
            if(s[i] == ')' && !st.empty())
            {
                int t = st.top();
                st.pop();
                dp[i] = t;
            }
            else if(s[i] == ')' && st.empty())
            {
                
            }
            else if(s[i] == '(')
            {
                st.push(i);
            }
        }
        for(int i = 1; i<l;++i)
        if(dp[i] > 0)
        {
            dp[i] = min(dp[dp[i] -1], dp[i]);
        }
        int best = 0;
        for(int i = 0; i<l;++i)
        {
            best = max(best, i - dp[i] + 1);
        }
        return best;
    }        
};