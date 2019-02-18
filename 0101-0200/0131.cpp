class Solution {
public:
    vector<vector<string>> ret;
    vector<string> seq;
    vector<vector<bool>> palins;

    void genPart(const string & src, int pos)
    {
        if (pos == src.size())
        {
            ret.push_back(seq);
            return;
        }
        for (int i = pos; i < src.size(); ++i)
            if (palins[pos][i])
            {
                seq.push_back(src.substr(pos, i - pos + 1));
                genPart(src, i + 1);
                seq.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        if (s.empty()) return ret;
        palins.resize(s.size());
        for (int i = 0; i < s.size(); ++i)
            palins[i].resize(s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            palins[i][i] = true;
            if (i > 0) palins[i][i - 1] = palins[i - 1][i] = (s[i] == s[i - 1]);
            for (int j = i - 2; j >= 0; --j)
            {
                palins[i][j] = palins[j][i] =
                    palins[i - 1][j + 1] && s[i] == s[j];
            }
        }
        genPart(s, 0);
        return ret;
    }
};