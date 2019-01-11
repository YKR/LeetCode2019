class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canReach[nums.size()];
        memset(canReach, 0, sizeof(canReach));
        canReach[0] = true;
        for (int i = 0; i < nums.size(); ++i)
            if (canReach[i])
                for (int j = min(nums[i], (int)nums.size() - i - 1); j >= 1; --j)
                {
                    if (canReach[i + j]) break;
                    canReach[i + j] = true;
                }
        return canReach[nums.size() - 1];
    }
};