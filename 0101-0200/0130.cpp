class Solution {
public:
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool flood_fill(vector<vector<char>>& board, int x, int y)
    {
        board[x][y] = 'F';
        bool canfill = true;
        for (int k = 0; k < 4; ++k)
        {
            int tox = x + dir[k][0];
            int toy = y + dir[k][1];
            if (tox < 0 || tox >= board.size() || toy < 0 || toy >= board[0].size())
            {
                canfill = false;
                continue;
            }
            if (board[tox][toy] == 'O' && !flood_fill(board, tox, toy))
            {
                canfill = false;
            }
        }
        return canfill;
    }

    void flood_do(vector<vector<char>>& board, int x, int y)
    {
        board[x][y] = 'X';
        for (int k = 0; k < 4; ++k)
        {
            int tox = x + dir[k][0];
            int toy = y + dir[k][1];
            if (board[tox][toy] == 'F')
            {
                flood_do(board, tox, toy);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'O')
                    if (flood_fill(board, i, j))
                    {
                        flood_do(board, i, j);
                    }
            }
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'F')
                    board[i][j] = 'O';
            }
    }
};