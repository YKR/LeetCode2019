class Solution {
public:
    string addBinary(string a, string b) {
        auto s2iv = [] (const string & s) -> vector<int> {
            vector<int> ret(s.size());
            for (int i = 0; i < s.size(); ++i)
                ret[s.size() - i - 1] = s[i] - '0';
            return ret;
        };
        auto iv2s = [] (const vector<int> & iv) -> string {
            string ret; ret.resize(iv.size());
            for (int i = 0; i < iv.size(); ++i)
                ret[iv.size() - i - 1] = iv[i] + '0';
            return ret;
        };
        vector<int> av, bv;
        if (a.size() > b.size()) av = s2iv(a), bv = s2iv(b);
        else av = s2iv(b), bv = s2iv(a);
        for (int i = 0; i < bv.size(); ++i) av[i] += bv[i];
        int p;
        for (p = 0; p < av.size() - 1; ++p) av[p+1] += av[p] / 2, av[p] %= 2;
        while (av[p] >= 2) av.push_back(av[p] / 2), av[p] %= 2, ++p;
        return iv2s(av);
    }
};