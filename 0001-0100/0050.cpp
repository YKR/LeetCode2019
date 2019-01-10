class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1, e = n < 0 ? 1 / x : x;
        unsigned int nn = n < 0 ? -n : n;
        while (nn)
        {
            if (nn & 1) ans *= e;
            e *= e;
            nn >>= 1;
        }
        return ans;
    }
};