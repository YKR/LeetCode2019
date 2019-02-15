class Solution {
public:
    int maxProfit_NSqr(vector<int>& prices) {
        int ans = 0;
        for (int d = 0; d < prices.size(); ++d)
        {
            int subans = 0;
            int maxdiff = 0;
            for (int i = 0, minPrice = INT_MAX; i < d; ++i)
            {
                minPrice = min(minPrice, prices[i]);
                maxdiff = max(maxdiff, prices[i] - minPrice);
            }
            subans += maxdiff;
            maxdiff = 0;
            for (int i = d, minPrice = INT_MAX; i < prices.size(); ++i)
            {
                minPrice = min(minPrice, prices[i]);
                maxdiff = max(maxdiff, prices[i] - minPrice);
            }
            subans += maxdiff;
            ans = max(ans, subans);
        }
        return ans;
    }
    
    int maxProfit_2Part(vector<int>& prices) {
        if (prices.empty()) return 0;
        int ans[2][prices.size()];
        memset(ans, 0, sizeof(ans));
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i)
        {
            minPrice = min(minPrice, prices[i]);
            ans[0][i] = prices[i] - minPrice;
            if (i > 0) ans[0][i] = max(ans[0][i], ans[0][i - 1]);
        }
        int maxPrice = INT_MIN;
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            maxPrice = max(maxPrice, prices[i]);
            ans[1][i] = maxPrice - prices[i];
            if (i < prices.size() - 1) ans[1][i] = max(ans[1][i], ans[1][i + 1]);
        }
        int realans = 0;
        for (int i = 0; i < prices.size(); ++i)
            realans = max(realans, ans[0][i] + ans[1][i]);
        return realans;
    }

    int maxProfit(vector<int>& prices) {
        //return maxProfit_NSqr(prices);
        //return maxProfit_2Part(prices);
        if (prices.empty()) return 0;
        int T = 2;
        int f[T + 1][prices.size()];
        memset(f, 0, sizeof(f));
        for (int t = 1; t <= T; ++t)
        {
            int maxVal = INT_MIN;
            for (int i = 0; i < prices.size(); ++i)
            {
                maxVal = max(maxVal, f[t - 1][i] - prices[i]);
                f[t][i] = prices[i] + maxVal;
                if (i > 0) f[t][i] = max(f[t][i], f[t][i - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i)
            ans = max(ans, f[T][i]);
        return ans;
    }
};