class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int lastNum = 0x7f7f7f7f;
        for (int i = 0; i < s.size(); i++)
        {
            int curNum;
            switch (s[i])
            {
                case 'I': curNum = 1; break;
                case 'V': curNum = 5; break;
                case 'X': curNum = 10; break;
                case 'L': curNum = 50; break;
                case 'C': curNum = 100; break;
                case 'D': curNum = 500; break;
                case 'M': curNum = 1000; break;
            }
            if (lastNum < curNum)
                ans += curNum - (lastNum << 1);
            else
                ans += curNum;
            lastNum = curNum;
        }
        return ans;
    }
};