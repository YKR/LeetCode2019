class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void recurse(int n, int left, int last)
    {
        if (left == 0)
        {
            ret.push_back(cur);
            return;
        }
        for (int i = last + 1; i < n - left + 1; ++i)
        {
            cur.push_back(i + 1);
            recurse(n, left - 1, i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        recurse(n, k, -1);
        return ret;
    }
};