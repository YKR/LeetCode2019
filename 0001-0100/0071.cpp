class Solution {
public:
    string simplifyPath(string path) {
        list<string> splitted;
        splitted.push_back("");
        int lastslash = 0;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                if (lastslash < i - 1)
                    splitted.push_back(path.substr(lastslash + 1, i - lastslash - 1));
                lastslash = i;
            }
        }
        if (lastslash < path.size() - 1)
            splitted.push_back(path.substr(lastslash + 1, path.size() - lastslash - 1));
        auto it = splitted.begin();
        while (++it != splitted.end())
        {
            if (*it == ".")
            {
                auto tmp = it;
                --it;
                splitted.erase(tmp);
            }
            else if (*it == "..")
            {
                auto tmp0 = it;
                --it;
                splitted.erase(tmp0);
                if (it != splitted.begin())
                {
                    auto tmp1 = it;
                    --it;
                    splitted.erase(tmp1);
                }
            }
        }
        splitted.erase(splitted.begin());
        string ret;
        for (auto && s : splitted)
        {
            ret += "/";
            ret += s;
        }
        if (ret.empty()) ret += "/";
        return ret;
    }
};