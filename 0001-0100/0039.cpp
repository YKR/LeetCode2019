class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurSum(int left, vector<int>& candidates, int pos)
    {
        int maxm = left / candidates[pos];
        if (pos == candidates.size() - 1)
        {
            if (left - maxm * candidates[pos] == 0)
            {
                cur.resize(cur.size() + maxm);
                for (int i = 0; i < maxm; ++i)
                    cur[cur.size() - i - 1] = candidates[pos];
                ret.push_back(cur);
                cur.resize(cur.size() - maxm);
            }
            return;
        }
        cur.resize(cur.size() + maxm + 1);
        for (int i = 0; i <= maxm; ++i)
            cur[cur.size() - i - 1] = candidates[pos];
        for (int i = maxm; i >= 0; --i)
        {
            cur.pop_back();
            recurSum(left - i * candidates[pos], candidates, pos + 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        recurSum(target, candidates, 0);
        return ret;
    }
};