class Solution {
public:
    vector<int> kmpJump;

    void buildKmp(string pattern)
    {
        kmpJump.clear();
        kmpJump.resize(pattern.size()+1);
        kmpJump[0] = -1;
        int matchHead = 0;
        for (int i = 1; i < kmpJump.size();)
        {
            if (pattern[i] == pattern[matchHead])
                kmpJump[i] = kmpJump[matchHead];
            else
            {
                kmpJump[i] = matchHead;
                while (matchHead >= 0 && pattern[i] != pattern[matchHead])
                    matchHead = kmpJump[matchHead];
            }
            ++i, ++matchHead;
        }
        kmpJump[pattern.size()] = matchHead;
    }

    int runKmp(string target, string pattern)
    {
        buildKmp(pattern);
        for (int i = 0, j = 0; i < target.size();)
        {
            if (target[i] == pattern[j] || j == -1)
                ++i, ++j;
            else
                j = kmpJump[j];
            if (j == pattern.size()) return i - j;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        return runKmp(haystack, needle);
    }
};