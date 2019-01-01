class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long originx = x;
        long long reversex = 0;
        while (x)
        {
            reversex *= 10;
            reversex += x % 10;
            x /= 10;
        }
        return reversex == originx;
    }
};