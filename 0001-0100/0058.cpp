class Solution {
public:
    int lengthOfLastWord(string s) {
        int endpos;
        for (endpos = s.size(); endpos > 0; --endpos)
            if (s[endpos - 1] != ' ') break;
        int ret;
        for (ret = 0; ret < endpos; ++ret)
            if (s[endpos - ret - 1] == ' ') break;
        return ret;
    }
};