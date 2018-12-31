class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int loop = (numRows - 1) * 2;
        string ret = s;
        int lmax = s.size() / loop;
        int rlen[numRows+2] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            int pos = i % loop;
            if (pos <= numRows - 1) ++rlen[pos];
            else ++rlen[loop-pos];
        }
        for (int i = numRows - 1; i > 0; i--)
            rlen[i] = rlen[i-1];
        rlen[0] = 0;
        for (int i = 1; i < numRows; i++)
            rlen[i] += rlen[i-1];
        for (int i = 0; i < s.size(); ++i)
        {
            int lnum = i / loop;
            int pos = i % loop;
            if (pos == 0 || pos == numRows - 1) ret[rlen[pos] + lnum] = s[i];
            else if (pos < numRows - 1) ret[rlen[pos] + lnum * 2] = s[i];
            else ret[rlen[loop-pos] + lnum * 2 + 1] = s[i];
        }
        return ret;
    }
};