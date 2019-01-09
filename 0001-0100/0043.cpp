class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> rn1(num1.size()), rn2(num2.size()), prod(num1.size() + num2.size() - 1);
        for (int i = 0; i < num1.size(); ++i)
            rn1[i] = num1[num1.size() - i - 1] - '0';
        for (int i = 0; i < num2.size(); ++i)
            rn2[i] = num2[num2.size() - i - 1] - '0';
        for (int i = 0; i < prod.size(); ++i)
            prod[i] = 0;
        for (int i = 0; i < num1.size(); ++i)
            for (int j = 0; j < num2.size(); ++j)
                prod[i + j] += rn1[i] * rn2[j];
        for (int i = 0; i < prod.size() - 1; ++i)
            prod[i + 1] += prod[i] / 10, prod[i] %= 10;
        while (prod.back() >= 10)
        {
            int b = prod.back();
            prod.back() %= 10;
            prod.push_back(b / 10);
        }
        string ret;
        ret.resize(prod.size());
        for (int i = 0; i < prod.size(); ++i)
            ret[i] = prod[prod.size() - i - 1] + '0';
        return ret;
    }
};