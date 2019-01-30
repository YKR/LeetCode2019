class Solution {
public:
    int CalcMaxArea(vector<int> & heights)
    {
        // same as 0084
        int ret = 0;
        vector<int> stk;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!stk.empty() && heights[stk.back()] >= heights[i])
            {
                int rangeHeightIndex = stk.back();
                stk.pop_back();
                int rangeBeginIndex = stk.empty() ? 0 : stk.back() + 1;
                ret = max(ret, (i - rangeBeginIndex) * heights[rangeHeightIndex]);
            }
            stk.push_back(i);
        }
        heights.pop_back();
        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m);
        for (auto && h : heights) h = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            ans = max(ans, CalcMaxArea(heights));
        }
        return ans;
    }
};