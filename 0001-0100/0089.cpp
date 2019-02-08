class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        ans[0] = 0;
        for (int i = 1; i < (1 << n); ++i)
            ans[i] = ans[i - 1] ^ (i & (-i));
        return ans;
    }
};