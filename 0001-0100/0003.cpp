class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int cur = 0;
        map<char, int> cm;
        for (int i = 0; i < s.size(); ++i)
        {
            ++cur;
            auto found = cm.find(s[i]);
            if (found != cm.end())
                cur = min(cur, i - found->second);
            if (ret < cur)
            {
                ret = cur;
            }
            cm[s[i]] = i;
        }
        return ret;
    }
};