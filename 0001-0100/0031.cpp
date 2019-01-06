class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos;
        for (pos = nums.size() - 2; pos >= 0; --pos)
            if (nums[pos] < nums[pos + 1])
                break;
        int suffixLen = nums.size() - pos - 1;
        for (int i = (suffixLen >> 1) - 1; i >= 0; --i)
            swap(nums[pos + 1 + i], nums[nums.size() - 1 - i]);
        if (pos > -1)
        {
            int l, r;
            for (l = pos + 1, r = nums.size(); l < r;)
            {
                int mid = (l + r) >> 1;
                if (nums[mid] <= nums[pos]) l = mid + 1;
                else r = mid;
            }
            swap(nums[pos], nums[r]);
        }
    }
};