class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, r;
        for (l = 0, r = nums.size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target)
            {
                if (nums[mid] > nums[l] && nums[l] <= target
                   || nums[mid] < nums[l])
                    r = mid;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] < nums[r - 1] && nums[r - 1] >= target
                   || nums[mid] > nums[r - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        if (r == nums.size() || nums[r] != target)
            return -1;
        return r;
    }
};