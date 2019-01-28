class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        int sbuc[256];
        int tbuc[256];
        memset(sbuc, 0, sizeof(sbuc));
        memset(tbuc, 0, sizeof(tbuc));
        int ansBegin = -1, ansLength = 0;
        for (auto && tt : t)
            ++tbuc[tt];
        int curNumSInT = 0;
        for (int l = 0, r = 0; r < s.size(); ++r)
        {
            if (sbuc[s[r]] < tbuc[s[r]])
                ++curNumSInT;
            ++sbuc[s[r]];
            while (sbuc[s[l]] > tbuc[s[l]])
            {
                --sbuc[s[l]];
                ++l;
            }
            if (curNumSInT == t.size()
                && (ansBegin == -1 || r - l + 1 < ansLength))
            {
                ansBegin = l;
                ansLength = r - l + 1;
            }
        }
        if (ansBegin == -1) return "";
        return s.substr(ansBegin, ansLength);
    }
};