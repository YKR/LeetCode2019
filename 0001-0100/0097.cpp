class Solution {
public:
    bool test(const vector<string> & strs, vector<int> & ptr)
    {
        if (ptr[0] == strs[0].size())
        {
            return true;
        }
        if (ptr[1] < strs[1].size() && strs[0][ptr[0]] == strs[1][ptr[1]])
        {
            ++ptr[0]; ++ptr[1];
            if (test(strs, ptr)) return true;
            --ptr[0]; --ptr[1];
        }
        if (ptr[2] < strs[2].size() && strs[0][ptr[0]] == strs[2][ptr[2]])
        {
            ++ptr[0]; ++ptr[2];
            if (test(strs, ptr)) return true;
            --ptr[0]; --ptr[2];
        }
        return false;
    }

    bool bruteForce(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        vector<string> strs(3);
        strs[0] = s3;
        strs[1] = s1;
        strs[2] = s2;
        vector<int> ptr(3);
        ptr[0] = ptr[1] = ptr[2] = 0;
        return test(strs, ptr);
    }

    bool isInterleave(string s1, string s2, string s3) {
        //return bruteForce(s1, s2, s3);
        if (s3.size() != s1.size() + s2.size()) return false;
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;
        bool f[s1.size() + 2][s2.size() + 2];
        memset(f, 0, sizeof(f));
        f[0][0] = true;
        for (int i = 0; i <= s1.size(); ++i)
            for (int j = 0; j <= s2.size(); ++j)
            {
                if (i < s1.size() && s1[i] == s3[i + j])
                    f[i + 1][j] = f[i + 1][j] || f[i][j];
                if (j < s2.size() && s2[j] == s3[i + j])
                    f[i][j + 1] = f[i][j + 1] || f[i][j];
            }
        return f[s1.size()][s2.size()];
    }
};