class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto reverseVec = [](vector<int> & vec){
            for (int i = 0; i < vec.size() / 2; ++i)
                swap(vec[i], vec[vec.size() - i - 1]);
        };
        int n = digits.size();
        reverseVec(digits);
        digits[0] += 1;
        int p;
        for (p = 0; p < n - 1; ++p)
            if (digits[p] >= 10)
            {
                digits[p + 1] += digits[p] / 10;
                digits[p] %= 10;
            }
        while (digits[p] >= 10)
        {
            digits.push_back(digits[p] / 10);
            digits[p] %= 10;
            ++p;
        }
        reverseVec(digits);
        return digits;
    }
};