class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        bool lastRowZero = false;
        for (int j = 0; j < m; ++j)
            if (matrix[0][j] == 0)
            {
                lastRowZero = true;
                break;
            }
        for (int i = 1; i < n; ++i)
        {
            bool thisRowZero = false;
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == 0)
                {
                    thisRowZero = true;
                    for (int k = i - 1; k >= 0; --k)
                        matrix[k][j] = 0;
                }
            for (int j = 0; j < m; ++j)
                if (matrix[i-1][j] == 0)
                    matrix[i][j] = 0;
            if (lastRowZero)
                for (int j = 0; j < m; ++j)
                    matrix[i-1][j] = 0;
            lastRowZero = thisRowZero;
        }
        if (lastRowZero)
            for (int j = 0; j < m; ++j)
                matrix[n-1][j] = 0;
    }
};