class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sums[2][triangle.size() + 2];
        int curs = 0;
        memset(sums[curs], 0, sizeof(sums[curs]));
        for (int i = 0; i < triangle.size(); ++i)
        {
            memset(sums[1 ^ curs], 0, sizeof(sums[1 ^ curs]));
            sums[1 ^ curs][0] = sums[curs][0] + triangle[i][0];
            for (int j = 0; j <= i; ++j)
            {
                sums[1 ^ curs][j] = min(sums[1 ^ curs][j], sums[curs][j] + triangle[i][j]);
                sums[1 ^ curs][j + 1] = sums[curs][j] + triangle[i][j];
            }
            curs = 1 ^ curs;
        }
        int ans = INT_MAX;
        for (int j = 0; j < triangle.size(); ++j)
            if (ans > sums[curs][j])
                ans = sums[curs][j];
        return ans;
    }
};