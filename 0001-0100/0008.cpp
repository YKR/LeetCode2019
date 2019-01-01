class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int ret = 0;
        // trim white space
        int realstart = 0;
        for (realstart = 0; realstart < str.size(); ++realstart)
        {
            if (str[realstart] != ' ')
                break;
        }
        // detect '-'
        if (str[realstart] == '-')
        {
            sign = -1;
            ++realstart;
        }
        else if (str[realstart] == '+')
        {
            ++realstart;
        }
        str = str.substr(realstart, str.size() - realstart);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] < '0' || str[i] > '9') break;
            if (sign == 1)
            {
                if (ret > INT_MAX / 10 || ret * 10 + (str[i] - '0') < 0) return INT_MAX;
            }
            else
            {
                if (ret < INT_MIN / 10 || ret * 10 - (str[i] - '0') > 0) return INT_MIN;
            }
            ret = ret * 10 + sign * (str[i] - '0');
        }
        return ret;
    }
};