class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurSum(int left, vector<pair<int, int>>& sorted, int pos)
    {
        if (pos == sorted.size())
        {
            if (left == 0)
                ret.push_back(cur);
            return;
        }
        int maxm = min(left / sorted[pos].first, sorted[pos].second);
        cur.resize(cur.size() + maxm + 1);
        for (int i = 0; i <= maxm; ++i)
            cur[cur.size() - i - 1] = sorted[pos].first;
        for (int i = maxm; i >= 0; --i)
        {
            cur.pop_back();
            recurSum(left - i * sorted[pos].first, sorted, pos + 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<pair<int, int>> sorted;
        for (auto && c : candidates)
        {
            if (!sorted.empty() && sorted.back().first == c)
                ++sorted.back().second;
            else
                sorted.push_back(make_pair(c, 1));
        }
        recurSum(target, sorted, 0);
        return ret;
    }
};