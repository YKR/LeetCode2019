class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stk;
        int ans = 0;
        stk.push_back(-1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stk.push_back(i);
            else
                if (stk.size() == 1)
                    stk[0] = i;
                else
                    stk.pop_back(), ans = max(ans, i - stk.back());
        }
        return ans = max(ans, (int)s.size() - 1 - stk.back());
    }
};