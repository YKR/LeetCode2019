class Solution {
public:
    const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    bool inbox(int x, int y, vector<vector<char>>& board)
    {
        return x >= 0 && x < board.size()
            && y >= 0 && y < board[0].size();
    }

    bool search(int x, int y, int index, vector<vector<char>>& board, string & word, bool * visited)
    {
        visited[x * board[0].size() + y] = true;
        bool ret = false;
        if (board[x][y] != word[index]) ret = false;
        else if (index == word.size() - 1) ret = true;
        else for (int i = 0; i < 4 && ret == false; ++i)
        {
            int tox = x + dir[i][0];
            int toy = y + dir[i][1];
            if (!inbox(tox, toy, board) || visited[tox * board[0].size() + toy]) continue;
            if (search(tox, toy, index + 1, board, word, visited)) ret = true;
        }
        visited[x * board[0].size() + y] = false;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        bool visited[board.size() * board[0].size()];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (search(i, j, 0, board, word, visited)) return true;
        return false;
    }
};