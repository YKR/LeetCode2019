class Solution {
public:
    int calcCombineNumber(int c, int p)
    {
        if (p > c / 2) p = c - p;
        long long ret = 1;
        for (int cc = c, pp = p; cc > c - p; --cc)
        {
            ret *= cc;
            while (pp > 1 && ret % pp == 0) ret /= pp, --pp;
        }
        return ret;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i)
            ret[i] = calcCombineNumber(rowIndex, i);
        return ret;
    }
};