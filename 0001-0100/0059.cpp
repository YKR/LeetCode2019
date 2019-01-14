class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        if (n == 0) return ret;
        for (int i = 0; i < n; ++i) ret.push_back(vector<int>(n));
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        bool used[n][n];
        memset(used, 0, sizeof(used));
        auto inbox = [n](int x, int y) -> bool { return x>=0 && y>=0 && x<n && y<n; };
        int curdir = 0;
        int curx = 0, cury = 0;
        for (int i = 0; i < n * n; ++i)
        {
            ret[curx][cury] = i + 1;
            used[curx][cury] = true;
            int tox = curx + dir[curdir][0];
            int toy = cury + dir[curdir][1];
            if (!inbox(tox, toy) || used[tox][toy])
            {
                curdir = (curdir + 1) % 4;
                tox = curx + dir[curdir][0];
                toy = cury + dir[curdir][1];
            }
            curx = tox;
            cury = toy;
        }
        return ret;
    }
};