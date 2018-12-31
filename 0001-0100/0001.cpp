class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        ret[0] = ret[1] = -1;
        
        map<int, vector<int>> sorted;
        for (int i = 0; i < nums.size(); i++)
            sorted[nums[i]].push_back(i);
        auto ii = sorted.begin(), jj = sorted.begin();
        for (int i = 0; i < sorted.size() - 1; i++)
            ++jj;
        while (ii != jj)
        {
            printf ("%d %d\n", ii->first, jj->first);
            if (ii->first + jj->first < target) ++ii;
            else if (ii->first + jj->first > target) --jj;
            else
            {
                ret[0] = min(ii->second[0], jj->second[0]);
                ret[1] = max(ii->second[0], jj->second[0]);
                return ret;
            }
        }
        if (ii == jj && ii->second.size() > 1)
        {
            ret[0] = min(ii->second[0], ii->second[1]);
            ret[1] = max(ii->second[0], ii->second[1]);
            return ret;
        }
        return ret;
    }
};