class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (auto && c : s)
        {
            switch (c)
            {
                case '(':
                case '[':
                case '{':
                    stk.push_back(c);
                    break;
                case ')':
                    if (stk.back() != '(') return false;
                    stk.pop_back();
                    break;
                case ']':
                    if (stk.back() != '[') return false;
                    stk.pop_back();
                    break;
                case '}':
                    if (stk.back() != '{') return false;
                    stk.pop_back();
                    break;
            }
        }
        return stk.empty();
    }
};