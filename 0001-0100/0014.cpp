class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int cur = 0;
        while (1)
        {
            bool endwhile = false;
            for (int i = 0; i < strs.size(); ++i)
            {
                if (cur == strs[i].size())
                {
                    endwhile = true;
                    break;
                }
            }
            if (endwhile) break;
            
            char ch = strs[0][cur];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i][cur] != ch)
                {
                    endwhile = true;
                    break;
                }
            }
            if (endwhile) break;
            ++cur;
        }
        if (cur == 0) return "";
        else return strs[0].substr(0, cur);
    }
};