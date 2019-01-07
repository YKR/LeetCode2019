class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int bits[5][10];
        auto bInsert = [&bits](int type, int index, int value) -> bool {
            if (bits[type][index] & (1 << value)) return false;
            bits[type][index] |= (1 << value); return true;
        };
        memset(bits, 0, sizeof(bits));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
            {
                int block = i / 3 * 3 + j / 3;
                if (board[i][j] == '.') continue;
                int value = board[i][j] - '0';
                if (!bInsert(0, i, value)
                    || !bInsert(1, j, value)
                    || !bInsert(2, block, value))
                    return false;
            }
        return true;
    }
};