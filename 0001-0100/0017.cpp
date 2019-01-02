class Solution {
public:
    vector<string> ret;
    string cur;

    void recur(const string & digits, int curpos, const string * dmap)
    {
        if (curpos == digits.size())
        {
            ret.push_back(cur);
            return;
        }
        const string & curmap = dmap[digits[curpos] - '0'];
        for (int i = 0; i < curmap.size(); ++i)
        {
            cur.push_back(curmap[i]);
            recur(digits, curpos + 1, dmap);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ret;
        string dmap[10] = {
            "", "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        recur(digits, 0, dmap);
        return ret;
    }
};