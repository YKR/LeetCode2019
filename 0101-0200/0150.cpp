class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
        for (auto && token : tokens)
        {
            if (token == "+")
            {
                int cur = stk.back(); stk.pop_back();
                stk.back() += cur;
            }
            else if (token == "-")
            {
                int cur = stk.back(); stk.pop_back();
                stk.back() -= cur;
            }
            else if (token == "*")
            {
                int cur = stk.back(); stk.pop_back();
                stk.back() *= cur;
            }
            else if (token == "/")
            {
                int cur = stk.back(); stk.pop_back();
                stk.back() /= cur;
            }
            else
            {
                stk.push_back(stoi(token));
            }
        }
        return stk.back();
    }
};