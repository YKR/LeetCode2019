class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i + offset < nums.size(); ++i)
        {
            nums[i] = nums[i + offset];
            if (i > 0 &&nums[i] == nums[i - 1])
                while (i + offset + 1 < nums.size() && nums[i + offset + 1] == nums[i])
                    ++offset;
        }
        nums.resize(nums.size() - offset);
        return nums.size();
    }
};