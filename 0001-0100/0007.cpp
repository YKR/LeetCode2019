class Solution {
public:
    int reverse(int x) {
        if (x == 0x8000000) return 0;
        int sign = 1;
        if (x < 0) x = -x, sign = -1;
        int ret = 0;
        for (int i = 0; x > 0;)
        {
            int retl1 = ret << 1;
            int retl2 = ret << 2;
            int retl3 = ret << 3;
            int retx10 = retl3 + retl1;
            int newret = retx10 + x % 10;
            if (retl1 < 0 || retl2 < 0 || retl3 < 0
               || retx10 < 0 || newret < 0) return 0;
            ret = newret;
            x /= 10;
        }
        ret *= sign;
        return ret;
    }
};