class Solution {
public:
    bool shouldTurn(vector<vector<int>>& matrix, bool * stepped, pair<int, int> xy) {
        return xy.first < 0 || xy.second < 0 || xy.first >= matrix.size() || xy.second >= matrix[0].size()
            || stepped[xy.first * matrix[0].size() + xy.second];
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty()) return ret;
        int numToBeStepped = matrix.size() * matrix[0].size();
        bool stepped[matrix.size() * matrix[0].size()];
        memset(stepped, 0, sizeof(stepped));
        pair<int, int> dir[4] = {
            make_pair(0, 1),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(-1, 0),
        };
        pair<int, int> ptr = make_pair(0, 0);
        int curdir = 0;
        for (int i = 0; i < numToBeStepped; ++i)
        {
            ret.push_back(matrix[ptr.first][ptr.second]);
            stepped[ptr.first * matrix[0].size() + ptr.second] = true;
            if (shouldTurn(matrix, stepped, make_pair(ptr.first + dir[curdir].first, ptr.second + dir[curdir].second)))
                curdir = (curdir + 1) % 4;
            ptr = make_pair(ptr.first + dir[curdir].first, ptr.second + dir[curdir].second);
        }
        return ret;
    }
};