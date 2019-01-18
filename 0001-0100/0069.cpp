class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        long long l = 0, r = x;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (mid * mid <= (long long)x) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};