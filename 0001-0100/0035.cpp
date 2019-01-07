class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l, r;
        for (l = 0, r = nums.size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};