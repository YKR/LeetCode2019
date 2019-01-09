class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            // bucket: nums[i] == i + 1
            while (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};