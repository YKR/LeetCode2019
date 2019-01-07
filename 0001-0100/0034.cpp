class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);
        int l, r;
        for (l = 0, r = nums.size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        ret[0] = (r == nums.size() || nums[r] != target) ? -1 : r;
        for (l = 0, r = nums.size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        ret[1] = (l == 0 || nums[l - 1] != target) ? -1 : l - 1;
        return ret;
    }
};