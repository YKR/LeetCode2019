class Solution {
public:
    int jump(vector<int>& nums) {
        int f[nums.size()];
        memset(f, 0x7f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = min((int)nums.size() - i - 1, nums[i]); j >= 1; --j)
            {
                if (f[i + j] > f[i] + 1)
                    f[i + j] = f[i] + 1;
                else break;
            }
        }
        return f[nums.size() - 1];
    }
};