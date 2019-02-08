class Solution {
public:
    vector<vector<int>> ret;
    vector<int> curset;

    void recur(vector<int> & nums, int index, bool lastused)
    {
        if (index == nums.size())
        {
            ret.push_back(curset);
            return;
        }
        if (lastused || nums[index] != nums[index - 1])
        {
            curset.push_back(nums[index]);
            recur(nums, index + 1, true);
            curset.pop_back();
        }
        recur(nums, index + 1, false);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        recur(nums, 0, true);
        return ret;
    }
};