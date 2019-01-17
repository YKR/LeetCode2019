class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        int f[m][n];
        memset(f, 0, sizeof(f));
        f[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int j = 1; j < n; ++j) f[0][j] = obstacleGrid[0][j] == 1 ? 0 : f[0][j-1];
        for (int i = 1; i < m; ++i)
        {
            f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i-1][0];
            for (int j = 1; j < n; ++j)
                f[i][j] = obstacleGrid[i][j] == 1 ? 0 : f[i][j-1] + f[i-1][j];
        }
        return f[m-1][n-1];
    }
};