class Solution {
public:
    bool isMatch(string s, string p) {
        string newp;
        string stars;
        for (auto && pp : p)
        {
            if (pp == '*') stars.back() = '*';
            else newp.push_back(pp), stars.push_back(' ');
        }
        int m = s.size(), n = newp.size();
        bool f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        for (int j = 1; j <= n; j++)
            f[0][j] = stars[j-1] == '*' ? f[0][j-1] : false;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (stars[j-1] == '*')
                    f[i][j] = f[i][j] || f[i][j-1];
                if (newp[j-1] == '.' || s[i-1] == newp[j-1])
                {
                    f[i][j] = f[i][j] || f[i-1][j-1];
                    if (stars[j-1] == '*')
                        f[i][j] = f[i][j] || f[i-1][j];
                }
            }
        return f[m][n];
    }
};