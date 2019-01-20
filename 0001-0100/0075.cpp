class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); ++i)
        {
            int numsi = nums[i];
            switch(nums[i])
            {
                case 0:
                    nums[cnt[0]] = 0;
                    if (cnt[1] > 0) nums[cnt[0] + cnt[1]] = 1;
                    if (cnt[2] > 0) nums[i] = 2;
                    break;
                case 1:
                    nums[cnt[0] + cnt[1]] = 1;
                    if (cnt[2] > 0) nums[i] = 2;
                    break;
                case 2:
                    break;
            }
            ++cnt[numsi];
        }
    }
};