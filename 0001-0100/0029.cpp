class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if (dividend == INT_MIN)
        {
            if (divisor == -0x1) return INT_MAX;
            if (divisor == INT_MIN) return 1;
        }
        if (divisor == INT_MIN)
        {
            return 0;
        }
        unsigned int udend, udsor;
        if (dividend < 0) udend = -dividend, sign = -sign;
        else udend = dividend;
        if (divisor < 0) udsor = -divisor, sign = -sign;
        else udsor = divisor;
        int ret = 0;
        int udsorBits = 0;
        for (udsorBits = 0; (udsor >> udsorBits) != 0; ++udsorBits);
        for (int i = 32 - udsorBits; i >= 0; --i)
            if (udend >= (udsor << i))
                udend -= (udsor << i),
                ret += 1 << i;
        return sign * ret;
    }
};