class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i + offset < nums.size(); ++i)
        {
            while (i+offset < nums.size()-1 && nums[i+offset] == nums[i+offset+1]) ++offset;
            nums[i] = nums[i+offset];
        }
        nums.resize(nums.size() - offset);
        return nums.size();
    }
};