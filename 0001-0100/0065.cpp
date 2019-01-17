class Solution {
public:
    void trim(string & s)
    {
        int l = 0, r = s.size();
        while (l < r && s[r-1] == ' ') --r;
        while (l < r && s[l] == ' ') ++l;
        if (l == r) s.clear();
        else s = s.substr(l, r - l);
    }
    bool isNumber(string s) {
        trim(s);
        // [+/-][0-9]*[.][0-9]*[e][+/-][0-9]+
        int stage = 0;
        bool digitBeforeDot = false;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            bool noProblem = false;
            switch (stage)
            {
                case 0:
                    if (c == '+' || c == '-') noProblem = true;
                    if (c >= '0' && c <= '9') stage = 1, digitBeforeDot = true, noProblem = true;
                    if (c == '.') stage = 2, noProblem = true;
                    break;
                case 1:
                    if (c >= '0' && c <= '9') noProblem = true;
                    if (c == '.') stage = 2, noProblem = true;
                    if (c == 'e') stage = 4, noProblem = true;
                    break;
                case 2:
                    if (c >= '0' && c <= '9') stage = 3, noProblem = true;
                    if (c == 'e' && digitBeforeDot) stage = 4, noProblem = true;
                    break;
                case 3:
                    if (c >= '0' && c <= '9') noProblem = true;
                    if (c == 'e') stage = 4, noProblem = true;
                    break;
                case 4:
                    if (c == '+' || c == '-') stage = 5, noProblem = true;
                    if (c >= '0' && c <= '9') stage = 6, noProblem = true;
                    break;
                case 5:
                    if (c >= '0' && c <= '9') stage = 6, noProblem = true;
                    break;
                case 6:
                    if (c >= '0' && c <= '9') noProblem = true;
                    break;
            }
            if (!noProblem) return false;
        }
        if (stage == 0 || stage == 2 && !digitBeforeDot || stage == 4 || stage == 5) return false;
        return true;
    }
};