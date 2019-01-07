
struct DancingLinks
{
    static const int Left = 0;
    static const int Right = 1;
    static const int Up = 2;
    static const int Down = 3;
    static const int Col = 4;
    static const int Row = 5;
    static const int TotalLinks = 6;

    struct Node
    {
        int links[TotalLinks];
        Node() { memset(links, -1, sizeof(links)); }
    };

    int numRows;
    int numCols;
    vector<Node> nodes; // head == nodes[0], cols[i] == nodes[i]
    vector<int> validRowNum;
    vector<int> solution;

    void Init(int _numCols)
    {
        nodes.clear();
        numRows = 0;
        numCols = _numCols;
        nodes.resize(numCols + 1);
        validRowNum.resize(numCols + 1);
        // init head and cols
        for (int i = 0; i <= numCols; ++i)
        {
            nodes[i].links[Left] = i - 1;
            nodes[i].links[Right] = i + 1;
            nodes[i].links[Row] = 0;
            nodes[i].links[Col] = i;
            nodes[i].links[Up] = i;
            nodes[i].links[Down] = i;
            validRowNum[i] = 0;
        }
        nodes[0].links[Left] = numCols;
        nodes[numCols].links[Right] = 0;
    }

    // row: 1~m; col: 1~n
    void AddRow(vector<int> & cols)
    {
        ++numRows;
        int st = nodes.size();
        nodes.resize(nodes.size() + cols.size());
        for (int i = 0; i < cols.size(); ++i)
        {
            nodes[i + st].links[Left] = i + st - 1;
            nodes[i + st].links[Right] = i + st + 1;
            nodes[i + st].links[Row] = numRows;
            nodes[i + st].links[Col] = cols[i];
            // update up and down
            nodes[i + st].links[Up] = nodes[cols[i]].links[Up];
            nodes[i + st].links[Down] = cols[i];
            nodes[nodes[i + st].links[Up]].links[Down] = i + st;
            nodes[nodes[i + st].links[Down]].links[Up] = i + st;
            ++validRowNum[nodes[i + st].links[Col]];
        }
        nodes[st].links[Left] = nodes.size() - 1;
        nodes[nodes.size() - 1].links[Right] = st;
    }

    void RemoveCol(int col)
    {
        nodes[nodes[col].links[Left]].links[Right] = nodes[col].links[Right];
        nodes[nodes[col].links[Right]].links[Left] = nodes[col].links[Left];
        for (int i = nodes[col].links[Down]; i != col; i = nodes[i].links[Down])
        {
            for (int j = nodes[i].links[Right]; j != i; j = nodes[j].links[Right])
            {
                nodes[nodes[j].links[Up]].links[Down] = nodes[j].links[Down];
                nodes[nodes[j].links[Down]].links[Up] = nodes[j].links[Up];
                --validRowNum[nodes[j].links[Col]];
            }
        }
    }

    void ResumeCol(int col)
    {
        nodes[nodes[col].links[Left]].links[Right] = col;
        nodes[nodes[col].links[Right]].links[Left] = col;
        for (int i = nodes[col].links[Up]; i != col; i = nodes[i].links[Up])
        {
            for (int j = nodes[i].links[Right]; j != i; j = nodes[j].links[Right])
            {
                nodes[nodes[j].links[Up]].links[Down] = j;
                nodes[nodes[j].links[Down]].links[Up] = j;
                ++validRowNum[nodes[j].links[Col]];
            }
        }
    }

    bool Solve()
    {
        if (nodes[0].links[Right] == 0) return true;
        int curCol = 0;
        int minRowNum = numRows + 0x7f7f;
        for (int i = nodes[0].links[Right]; i != 0; i = nodes[i].links[Right])
            if (validRowNum[i] < minRowNum)
                minRowNum = validRowNum[i], curCol = i;
        RemoveCol(curCol);
        for (int curNode = nodes[curCol].links[Down]; curNode != curCol; curNode = nodes[curNode].links[Down])
        {
            solution.push_back(nodes[curNode].links[Row]);
            for (int i = nodes[curNode].links[Right]; i != curNode; i = nodes[i].links[Right])
                RemoveCol(nodes[i].links[Col]);
            if (Solve()) return true;
            for (int i = nodes[curNode].links[Left]; i != curNode; i = nodes[i].links[Left])
                ResumeCol(nodes[i].links[Col]);
            solution.pop_back();
        }
        ResumeCol(curCol);
        return false;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        DancingLinks dlx;
        dlx.Init(324);
        vector<pair<pair<int, int>, int>> moves(1);
        int bits[5][10];
        memset(bits, 0, sizeof(bits));
        auto AddSudokuRow = [&dlx, &moves, &bits] (int x, int y, int value, bool addToBits = false) -> void {
            int b = (x / 3) * 3 + y / 3;
            if ((bits[0][x] & (1 << value))
                || (bits[1][y] & (1 << value))
                || (bits[2][b] & (1 << value)))
                return;
            vector<int> rowAdding(4);
            rowAdding[0] = 1 + x * 9 + y;
            rowAdding[1] = 82 + x * 9 + value;
            rowAdding[2] = 163 + y * 9 + value;
            rowAdding[3] = 244 + b * 9 + value;
            dlx.AddRow(rowAdding);
            moves.push_back(make_pair(make_pair(x, y), value));
            if (addToBits)
            {
                bits[0][x] |= 1 << value;
                bits[1][y] |= 1 << value;
                bits[2][b] |= 1 << value;
            }
        };
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    AddSudokuRow(i, j, board[i][j] - '1', true);
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.')
                    for (int v = 0; v < 9; ++v)
                        AddSudokuRow(i, j, v);
        dlx.Solve();
        for (int i = 0; i < dlx.solution.size(); ++i)
        {
            auto & move = moves[dlx.solution[i]];
            board[move.first.first][move.first.second] = move.second + '1';
        }
    }
};