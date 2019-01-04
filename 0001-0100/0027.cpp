class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int offset = 0;
        for (int i = 0; i + offset < nums.size(); ++i)
        {
            while (i+offset < nums.size() && nums[i+offset] == val) ++offset;
            if (i+offset == nums.size()) break;
            nums[i] = nums[i+offset];
        }
        nums.resize(nums.size() - offset);
        return nums.size();
    }
};