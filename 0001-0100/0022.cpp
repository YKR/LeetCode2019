class Solution {
public:
    string cur;
    vector<string> ret;
    char mapping[256];

    void gen(int i, int stk, int n)
    {
        if (i == n)
        {
            ret.push_back(cur);
            return;
        }
        if (stk < n && i + stk < n)
        {
            cur.push_back('(');
            gen(i, stk+1, n);
            cur.pop_back();
        }
        if (stk > 0)
        {
            cur.push_back(')');
            gen(i+1, stk-1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        gen(0, 0, n);
        return ret;
    }
};