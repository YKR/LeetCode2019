class Solution {
public:
    vector<string> ret;
    string curip;
    void sch(const string & src, int index, int accumFrag, int dotsLeft)
    {
        if (dotsLeft < 0) return;
        if (index == src.size())
        {
            if (dotsLeft > 0 || curip.back() == '.') return;
            ret.push_back(curip);
            return;
        }
        int curAccum = accumFrag * 10 + src[index] - '0';
        if (curAccum > 255) return;
        curip.push_back(src[index]);
        curip.push_back('.');
        sch(src, index + 1, 0, dotsLeft - 1);
        curip.pop_back();
        if (!(index < src.size() - 1 && src[index] == '0' && accumFrag == 0))
            sch(src, index + 1, curAccum, dotsLeft);
        curip.pop_back();
    }

    vector<string> restoreIpAddresses(string s) {
        sch(s, 0, 0, 3);
        return ret;
    }
};