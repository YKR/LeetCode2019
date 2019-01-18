class Solution {
public:

    struct m2x2
    {
        int m[2][2];
        m2x2 operator* (const m2x2 & other)
        {
            m2x2 ret;
            memset(ret.m, 0, sizeof(ret.m));
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    for (int k = 0; k < 2; ++k)
                        ret.m[i][j] += m[i][k] * other.m[k][j];
            return ret;
        }
    };

    int climbStairs(int n) {
        // f[n] = f[n-1] + f[n-2] : fibonacci
        // f[0] = 1, f[1] = 1
        // (f[n], f[n-1]) = (f[n-1], f[n-2]) * ([1 1]) = (f[1], f[0]) * ([1 1]) ^ (n-1)
        //                                     ([1 0])                  ([1 0])
        --n;
        m2x2 m, e;
        memset(m.m, 0, sizeof(m.m));
        memset(e.m, 0, sizeof(e.m));
        m.m[0][0] = m.m[1][1] = 1;
        e.m[0][0] = e.m[0][1] = e.m[1][0] = 1;
        while (n)
        {
            if (n & 1) m = m * e;
            e = e * e;
            n >>= 1;
        }
        int ans = m.m[0][0] + m.m[1][0];
        return ans;
    }
};