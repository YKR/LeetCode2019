class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s == "") return "";
        int ret = 1, retpos = 1;
        int n = s.size();
        bool f[n+1][n+1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; i++)
            f[i][0] = f[i][1] = true;
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= i; j++)
            {
                f[i][j] = (f[i-1][j-2] && s[i-j] == s[i-1]);
                if (f[i][j] && ret < j) ret = j, retpos = i;
            }
        return s.substr(retpos - ret, ret);
    }
};