class Solution {
public:

    void tryDecrease(int & num, int decn, string & ret, const string & addStr)
    {
        int lo = num - decn;
        if (lo >= 0)
        {
            ret += addStr;
            num -= decn;
        }
    }
    
    void tryDivide(int & num, int divn, string & ret, const string & addStr)
    {
        int tms = num / divn;
        while (tms--) ret += addStr;
        num %= divn;
    }

    string intToRoman(int num) {
        string ret;
        
        tryDivide(num, 1000, ret, "M");
        tryDecrease(num, 900, ret, "CM");
        tryDecrease(num, 500, ret, "D");
        tryDecrease(num, 400, ret, "CD");
        
        tryDivide(num, 100, ret, "C");
        tryDecrease(num, 90, ret, "XC");
        tryDecrease(num, 50, ret, "L");
        tryDecrease(num, 40, ret, "XL");
        
        tryDivide(num, 10, ret, "X");
        tryDecrease(num, 9, ret, "IX");
        tryDecrease(num, 5, ret, "V");
        tryDecrease(num, 4, ret, "IV");
        
        tryDivide(num, 1, ret, "I");
        
        return ret;
    }
};