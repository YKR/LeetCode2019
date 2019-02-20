class Solution {
public:
    int singleNumber_Hash(vector<int>& nums) {
        unordered_set<int> nset;
        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_set<int>::iterator found;
            if ((found = nset.find(nums[i])) != nset.end())
                nset.erase(found);
            else
                nset.insert(nums[i]);
        }
        return *nset.begin();
    }

    int singleNumber(vector<int>& nums) {
        //return singleNumber_Hash(nums);
        int ans = 0;
        for (auto && nn : nums)
            ans ^= nn;
        return ans;
    }
};