class Solution {
public:
    string countAndSay(int n) {
        string cas[31];
        cas[1] = "1";
        cas[2] = "11";
        for (int i = 3; i <= n; ++i)
        {
            int last = 0;
            int j = 1;
            while (j <= cas[i-1].size())
            {
                for (; j < cas[i-1].size(); ++j)
                    if (cas[i-1][j] != cas[i-1][j-1])
                        break;
                cas[i] += to_string(j-last);
                cas[i].push_back(cas[i-1][j-1]);
                last = j;
                ++j;
            }
        }
        return cas[n];
    }
};