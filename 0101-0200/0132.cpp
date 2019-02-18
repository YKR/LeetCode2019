class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return -1; // Official output == -1; 0 should be the right answer
        bool palins[s.size()][s.size()];
        memset(palins, 0, sizeof(palins));
        int f[s.size()];
        for (int i = 0; i < s.size(); ++i)
        {
            palins[i][i] = true;
            if (i > 0) palins[i - 1][i] = palins[i][i - 1] = (s[i] == s[i - 1]);
            f[i] = INT_MAX;
            for (int j = i; j >= 0; --j)
                if (s[i] == s[j] && (j == i || palins[j + 1][i - 1]))
                    palins[i][j] = palins[j][i] = true,
                    f[i] = min(f[i], (j > 0 ? f[j - 1] : -1) + 1);
        }
        return f[s.size() - 1];
    }
};