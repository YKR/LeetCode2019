class Solution {
public:
    int numDistinct(string s, string t) {
        long long f[s.size() + 2][t.size() + 2];
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= s.size(); ++i) f[i][0] = 1;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                f[i][j] = f[i - 1][j] + (s[i - 1] == t[j - 1] ? f[i - 1][j - 1] : 0);
            }
        }
        return f[s.size()][t.size()];
    }
};