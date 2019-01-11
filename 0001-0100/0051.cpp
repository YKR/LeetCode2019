class Solution {
public:
    vector<vector<string>> ret;

    vector<pair<int, int>> cur;

    void search(int row, bool * col, bool * slash, bool * backslash, int n)
    {
        if (row == n)
        {
            string blankstr;
            vector<string> ans(n);
            blankstr.resize(n);
            for (int i = 0; i < n; ++i) blankstr[i] = '.';
            for (int i = 0; i < n; ++i)
                ans[i] = blankstr;
            for (auto && xy : cur)
                ans[xy.first][xy.second] = 'Q';
            ret.push_back(ans);
            return;
        }
        for (int c = 0; c < n; ++c)
        {
            int sl = c + row, bs = c - row + n;
            if (col[c] || slash[sl] || backslash[bs]) continue;
            cur.push_back(make_pair(row, c));
            col[c] = true;
            slash[sl] = true;
            backslash[bs] = true;
            search (row + 1, col, slash, backslash, n);
            cur.pop_back();
            col[c] = false;
            slash[sl] = false;
            backslash[bs] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
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