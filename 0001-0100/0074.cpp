class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int l, r;
        for (l = 0, r = matrix.size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (matrix[mid].back() < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (r == matrix.size()) return false;
        int row = r;
        for (l = 0, r = matrix[row].size(); l < r;)
        {
            int mid = (l + r) >> 1;
            if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (r == matrix[row].size()) return false;
        return matrix[row][r] == target;
    }
};