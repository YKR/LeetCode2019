class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;
    vector<pair<int, int>> dupnums;
    int totalNums;
    void perm(int * used, int totalUsed)
    {
        if (totalUsed >= totalNums)
        {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i < dupnums.size(); ++i)
        {
            if (used[i] < dupnums[i].second)
            {
                ++used[i];
                cur.push_back(dupnums[i].first);
                perm(used, totalUsed + 1);
                cur.pop_back();
                --used[i];
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto && c : nums)
        {
            if (!dupnums.empty() && c == dupnums.back().first)
                ++dupnums.back().second;
            else
                dupnums.push_back(make_pair(c, 1));
        }
        int used[dupnums.size()];
        memset(used, 0, sizeof(used));
        totalNums = nums.size();
        perm(used, 0);
        return ret;
    }
};