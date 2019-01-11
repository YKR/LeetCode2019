class Solution {
public:
    int linearSolution(vector<int> & nums)
    {
        int ans = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            cur += nums[i];
            if (ans < cur) ans = cur;
            if (cur < 0) cur = 0;
        }
        return ans;
    }
    
    vector<int> sch(vector<int> & nums, int st, int en)
    {
        // 0 for maxsub, 1 for maxsub begin from st, 2 for maxsub begin from en, 3 for add all
        vector<int> ret(4);
        if (st + 1 == en)
        {
            ret[0] = ret[1] = ret[2] = ret[3] = nums[st];
            return ret;
        }
        int mid = (st + en) >> 1;
        auto left = sch(nums, st, mid);
        auto right = sch(nums, mid, en);
        ret[0] = max(left[2] + right[1], max(left[0], right[0]));
        ret[1] = max(left[1], right[1] + left[3]);
        ret[2] = max(right[2], left[2] + right[3]);
        ret[3] = left[3] + right[3];
        return ret;
    }

    int divConqSolution(vector<int> & nums)
    {
        auto ans = sch(nums, 0, nums.size());
        return ans[0];
    }

    int maxSubArray(vector<int>& nums) {
        //return linearSolution(nums);
        return divConqSolution(nums);
    }
};