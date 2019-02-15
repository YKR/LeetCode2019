class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j;)
        {
            while (i < j && !(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) ++i;
            while (i < j && !(s[j] >= '0' && s[j] <= '9' || s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) --j;
            if (i >= j) break;
            char left = s[i] >= 'a' ? s[i] - 'a' + 'A' : s[i];
            char right = s[j] >= 'a' ? s[j] - 'a' + 'A' : s[j];
            if (left != right) return false;
            ++i, --j;
        }
        return true;
    }
};