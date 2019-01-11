class Solution {
public:
    int ret;

    void search(int row, bool * col, bool * slash, bool * backslash, int n)
    {
        if (row == n)
        {
            ++ret;
            return;
        }
        for (int c = 0; c < n; ++c)
        {
            int sl = c + row, bs = c - row + n;
            if (col[c] || slash[sl] || backslash[bs]) continue;
            col[c] = true;
            slash[sl] = true;
            backslash[bs] = true;
            search (row + 1, col, slash, backslash, n);
            col[c] = false;
            slash[sl] = false;
            backslash[bs] = false;
        }
    }

    int totalNQueens(int n) {
        ret = 0;
        bool col[n];
        bool slash[n << 1];
        bool backslash[n << 1];
        memset (col, 0, sizeof(col));
        memset (slash, 0, sizeof(slash));
        memset (backslash, 0, sizeof(backslash));
        search(0, col, slash, backslash, n);
        return ret;
    }
};