class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numsBits[32];
        memset(numsBits, 0, sizeof(numsBits));
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < 32; ++j)
            {
                numsBits[j] += (nums[i] >> j) & 1;
            }
        int ans = 0;
        for (int j = 0; j < 32; ++j)
        {
            ans += (numsBits[j] % 3) << j;
        }
        return ans;
    }
};