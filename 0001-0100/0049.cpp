class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, int> groups;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            auto found = groups.find(s);
            if (found == groups.end())
            {
                ret.push_back(vector<string>());
                groups[s] = ret.size() - 1;
                found = groups.find(s);
            }
            ret[found->second].push_back(strs[i]);
        }
        return ret;
    }
};