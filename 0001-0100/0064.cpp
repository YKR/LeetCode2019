class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
        if ((m = grid.size()) == 0 || (n = grid[0].size()) == 0)
            return 0;
        int f[m][n];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int minp = 0x7f7f7f7f;
                if (i > 0) minp = min(minp, f[i-1][j]);
                if (j > 0) minp = min(minp, f[i][j-1]);
                if (minp == 0x7f7f7f7f) minp = 0;
                f[i][j] = minp + grid[i][j];
            }
        return f[m-1][n-1];
    }
};