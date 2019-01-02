class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = 0x7f7f7f7f;
        int ret = 0;
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            for (int j = i - 1, k = i + 1; j >= 0 && k < nums.size();)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ret = sum;
                }
                if (sum > target) --j;
                else if (sum < target) ++k;
                else return target;
            }
        }
        return ret;
    }
};