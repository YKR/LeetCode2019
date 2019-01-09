class Solution {
public:

    vector<vector<int>> ret;
    vector<int> perm;

    void dfs(vector<int>& nums, bool * used, int totalUsed)
    {
        if (totalUsed == nums.size())
        {
            ret.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                perm.push_back(nums[i]);
                dfs(nums, used, totalUsed + 1);
                perm.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        bool used[nums.size()];
        memset(used, 0, sizeof(used));
        dfs(nums, used, 0);
        return ret;
    }
};