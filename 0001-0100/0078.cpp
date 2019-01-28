class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurse(vector<int> & nums, int curp)
    {
        if (curp == nums.size())
        {
            ret.push_back(cur);
            return;
        }
        recurse(nums, curp + 1);
        cur.push_back(nums[curp]);
        recurse(nums, curp + 1);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        recurse(nums, 0);
        return ret;
    }
};