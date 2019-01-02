class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> quadlet(4);
        if (nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> nnn;
        nnn.push_back(make_pair(nums[0], 1));
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nnn.back().first)
                ++nnn.back().second;
            else
                nnn.push_back(make_pair(nums[i], 1));
        }
        int n = nnn.size();
        auto sum = [&nnn](int ii, int jj, int kk, int ll) -> int {
            return nnn[ii].first + nnn[jj].first + nnn[kk].first + nnn[ll].first;
        };
        auto addquad = [&nnn, &ret, &quadlet](int ii, int jj, int kk, int ll) {
            quadlet[0] = nnn[ii].first;
            quadlet[1] = nnn[jj].first;
            quadlet[2] = nnn[kk].first;
            quadlet[3] = nnn[ll].first;
            ret.push_back(quadlet);
        };
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                for (int k = 0, l = n-1; k < j; ++k)
                {
                    while (sum(i, j, k, l) > target && l > i) --l;
                    if (l > i && sum(i, j, k, l) == target)
                        addquad(k, j, i, l);
                    if (nnn[k].second >=2 && sum(i, j, k, k) == target)
                        addquad(k, k, j, i);
                    if (nnn[j].second >=2 && sum(i, j, k, j) == target)
                        addquad(k, j, j, i);
                    if (nnn[i].second >=2 && sum(i, j, k, i) == target)
                        addquad(k, j, i, i);
                }
                if (nnn[i].second >=2 && nnn[j].second >=2 && sum(i, i, j, j) == target)
                    addquad(j, j, i, i);
                if (nnn[i].second >=3 && sum(i, i, i, j) == target)
                    addquad(j, i, i, i);
                if (nnn[j].second >=3 && sum(i, j, j, j) == target)
                    addquad(j, j, j, i);
            }
            if (nnn[i].second >=4 && sum(i, i, i, i) == target)
                addquad(i, i, i, i);
        }
        return ret;
    }
};