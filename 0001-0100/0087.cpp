class Solution {
public:
    bool test(const string & s1, const string & s2,
        int st1, int st2, int length)
    {
        if (length == 1 && s1[st1] == s2[st2]) return true;
        vector<int> bucket1(128);
        vector<int> bucket2(128);
        vector<int> bucket2rev(128);
        for (int i = 0; i < 128; ++i)
        {
            bucket1[i] = 0;
            bucket2[i] = 0;
            bucket2rev[i] = 0;
        }
        for (int i = 1; i < length; ++i)
        {
            ++bucket1[s1[st1 + i - 1]];
            ++bucket2[s2[st2 + i - 1]];
            ++bucket2rev[s2[st2 + length - i]];
            if (bucket1 == bucket2)
            {
                if (test(s1, s2, st1, st2, i)
                    && test(s1, s2, st1 + i, st2 + i, length - i))
                    return true;
            }
            if (bucket1 == bucket2rev)
            {
                if (test(s1, s2, st1, st2 + length - i, i)
                    && test(s1, s2, st1 + i, st2, length - i))
                    return true;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        return test(s1, s2, 0, 0, s1.size());
    }
};