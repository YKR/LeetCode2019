class Solution {
public:
    int longestConsecutive_UnionFind(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i)
            numsMap[nums[i]] = i;
        int uf[nums.size()];
        int clusterSize[nums.size()];
        for (int i = 0; i < nums.size(); ++i)
            uf[i] = i, clusterSize[i] = 1;
        function<int(int)> unionFind = [&uf, &unionFind](int cur) -> int {
            if (uf[cur] == cur) return cur;
            return uf[cur] = unionFind(uf[cur]);
        };
        for (int i = 0; i < nums.size(); ++i)
        {
            if (numsMap[nums[i]] != i) continue;
            auto other = numsMap.begin();
            if ((other = numsMap.find(nums[i] - 1)) != numsMap.end()
                && unionFind(other->second) != unionFind(i))
            {
                clusterSize[unionFind(other->second)] += clusterSize[unionFind(i)];
                uf[unionFind(i)] = unionFind(other->second);
            }
            if ((other = numsMap.find(nums[i] + 1)) != numsMap.end()
                && unionFind(other->second) != unionFind(i))
            {
                clusterSize[unionFind(other->second)] += clusterSize[unionFind(i)];
                uf[unionFind(i)] = unionFind(other->second);
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (unionFind(i) == i)
                ans = max(ans, clusterSize[i]);
        return ans;
    }

    int longestConsecutive(vector<int>& nums) {
        //return longestConsecutive_UnionFind(nums);
        if (nums.empty()) return 0;
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i)
            numsMap[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (numsMap.find(nums[i] - 1) == numsMap.end())
            {
                int len = 0;
                while (numsMap.find(nums[i] + len) != numsMap.end()) ++len;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};