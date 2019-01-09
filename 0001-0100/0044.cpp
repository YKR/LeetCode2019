class Solution {
public:
    bool isMatch(string s, string p) {
        bool f[s.size() + 1][p.size() + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = true;
        for (int j = 1; j <= p.size(); ++j)
            if (p[j-1] == '*') f[0][j] = f[0][j] || f[0][j-1];
        for (int i = 1; i <= s.size(); ++i)
            for (int j = 1; j <= p.size(); ++j)
            {
                if (s[i-1] == p[j-1] || p[j-1] == '?' || p[j-1] == '*')
                    f[i][j] = f[i][j] || f[i-1][j-1];
                if (p[j-1] == '*')
                    f[i][j] = f[i][j] || f[i-1][j] || f[i][j-1];
            }
        return f[s.size()][p.size()];
    }
};