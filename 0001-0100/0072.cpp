class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) dp[i][0] = i;
        for (int j = 1; j <= m; ++j) dp[0][j] = j;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + (word1[i-1] != word2[j-1]));
        return dp[n][m];
    }
};