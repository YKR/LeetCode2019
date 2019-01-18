class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if (words.empty()) return ret;
        auto genRow = [&words, &maxWidth] (int stp, int enp) -> string {
            int numWords = enp - stp + 1;
            int numSpaces = maxWidth;
            for (int i = stp; i <= enp; ++i)
                numSpaces -= words[i].size();
            string ret = words[stp];
            if (numWords == 1)
            {
                for (int j = numSpaces; j > 0; --j)
                    ret.push_back(' ');
            }
            else
            {
                int averageSpaces = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                for (int i = 1; i < numWords; ++i)
                {
                    for (int j = averageSpaces + (i <= extraSpaces); j > 0; --j)
                        ret.push_back(' ');
                    ret += words[stp + i];
                }
            }
            return ret;
        };
        int p;
        int accumLength = words[0].size(), startp = 0;
        for (p = 1; p < words.size(); ++p)
        {
            if (accumLength + 1 + words[p].size() > maxWidth)
            {
                ret.push_back(genRow(startp, p - 1));
                accumLength = words[p].size();
                startp = p;
            }
            else
            {
                accumLength += 1 + words[p].size();
            }
        }
        string lastline;
        lastline += words[startp];
        for (int i = startp + 1; i < p; ++i) lastline += " " + words[i];
        while (lastline.size() < maxWidth) lastline.push_back(' ');
        ret.push_back(lastline);
        return ret;
    }
};