class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        int nproduct[n];
        bool used[n+1];
        nproduct[0] = 1;
        for (int i = 1; i < n; ++i)
            nproduct[i] = nproduct[i - 1] * i;
        memset(used, 0, sizeof(used));
        for (int i = n - 1; i >= 0; --i)
        {
            int quotient = (k - 1) / nproduct[i] + 1;
            int j, cnt;
            for (j = 1, cnt = quotient; j <= n; ++j)
            {
                if (!used[j]) --cnt;
                if (cnt == 0) break;
            }
            ret.push_back(j + '0');
            used[j] = true;
            k -= (quotient - 1) * nproduct[i];
        }
        return ret;
    }
};