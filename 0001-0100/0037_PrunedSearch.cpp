class Solution {
public:
    static const int rectsize = 9;
    int rowbits[rectsize];
    int colbits[rectsize];
    int blkbits[rectsize];
    
    int initrect(vector<vector<char>>& board)
    {
        int ret = 0;
        memset(rowbits, 0, rectsize * sizeof(int));
        memset(colbits, 0, rectsize * sizeof(int));
        memset(blkbits, 0, rectsize * sizeof(int));
        
        for (int i = 0; i < rectsize; i++)
        {
            vector<char> & row = board[i];
            for (int j = 0; j < rectsize; j++)
            {
                int k = (i/3)*3 + j/3;
                
                char & curch = row[j];
                if (curch == '.')
                {
                    ret++;
                    continue;
                }
                int curnum = curch - '1';
                
                int bit = 1 << curnum;
                rowbits[i] |= bit;
                colbits[j] |= bit;
                blkbits[k] |= bit;
            }
        }
        
        return ret;
    }
    
    void rollback(vector<vector<char>>& board, vector<int> & seq, int seqstart)
    {
        for (int ss = seqstart; ss < seq.size(); ss++)
        {
            int cur = seq[ss];
            int ii = cur/rectsize/rectsize;
            int jj = cur/rectsize%rectsize;
            int nn = cur%rectsize;
            int kk = (ii/3)*3 + jj/3;
            int bbit = 1 << nn;
            rowbits[ii] ^= bbit;
            colbits[jj] ^= bbit;
            blkbits[kk] ^= bbit;
            board[ii][jj] = '.';
        }
        seq.resize(seqstart);
    }
    
    bool deduce(vector<vector<char>>& board, int rest, vector<int> & seq, int seqstart)
    {
        const int full = 0x1FF;
        
        if (rest == 0) return true;
        
        bool deduce_flag = true;

        int lpi, lpj, lpn;

        while (deduce_flag)
        {
            lpi = -1;
            lpj = -1;
            lpn = rectsize + 1;

            deduce_flag = false;
            for (int i = 0; i < rectsize; i++)
            {
                vector<char> & row = board[i];
                for (int j = 0; j < rectsize; j++)
                {
                    int k = (i/3)*3 + j/3;

                    char & curch = row[j];
                    if (curch != '.') continue;

                    int merge = rowbits[i] | colbits[j] | blkbits[k];
                    if (merge == full)
                    {
                        rollback(board, seq, seqstart);
                        return false;
                    }
                    int nnum = 0;
                    for (int n = 0; n < rectsize; n++)
                    {
                        int bit = 1 << n;
                        if (merge & bit) continue;
                        if ((merge | bit) == full)
                        {
                            curch = n + '1';
                            rowbits[i] |= bit;
                            colbits[j] |= bit;
                            blkbits[k] |= bit;
                            seq.push_back(i*rectsize*rectsize + j*rectsize + n);
                            rest--;
                            if (rest == 0) return true;
                            deduce_flag = true;
                            break;
                        }
                        nnum++;
                    }
                    if (nnum && nnum < lpn)
                    {
                        lpi = i;
                        lpj = j;
                        lpn = nnum;
                    }
                }
            }
        }

        if (rest > 0)
        {
            if (lpi == -1)
            {
                rollback(board, seq, seqstart);
                return false;
            }

            int i = lpi;
            int j = lpj;
            int k = (i/3)*3 + j/3;
            int merge = rowbits[i] | colbits[j] | blkbits[k];
            if (merge == full)
            {
                rollback(board, seq, seqstart);
                return false;
            }
            for (int n = 0; n < rectsize; n++)
            {
                int bit = 1 << n;
                if (merge & bit) continue;

                board[i][j] = n + '1';
                rowbits[i] |= bit;
                colbits[j] |= bit;
                blkbits[k] |= bit;
                seq.push_back(i*rectsize*rectsize + j*rectsize + n);
                if (deduce(board, rest - 1, seq, seq.size())) return true;
                seq.pop_back();
                rowbits[i] ^= bit;
                colbits[j] ^= bit;
                blkbits[k] ^= bit;
                board[i][j] = '.';
            }
            rollback(board, seq, seqstart);
            return false;
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int rest = initrect(board);
        vector<int> seq;
        deduce(board, rest, seq, 0);
    }
};