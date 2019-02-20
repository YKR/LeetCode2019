class Solution {
public:
    struct TrieNode
    {
        int depth;
        bool endOfWord;
        int nexts[128];
        TrieNode(int _d, bool _e) : depth(_d), endOfWord(_e) { memset(nexts, 0, sizeof(nexts)); }
    };

    vector<TrieNode> trieNodes;

    void initTrieTree()
    {
        trieNodes.clear();
        trieNodes.push_back(TrieNode(0, false));
    }

    void addToTrieTree(const string & str, int p, int cur)
    {
        if (p == str.size())
        {
            trieNodes[cur].endOfWord = true;
            return;
        }
        if (!trieNodes[cur].nexts[str[p]])
        {
            trieNodes.push_back(TrieNode(trieNodes[cur].depth + 1, false));
            trieNodes[cur].nexts[str[p]] = trieNodes.size() - 1;
        }
        addToTrieTree(str, p + 1, trieNodes[cur].nexts[str[p]]);
    }

    vector<char> searched;
    bool search(const string & str, int p, int cur)
    {
        if (p == str.size())
        {
            if (trieNodes[cur].endOfWord) return true;
            return false;
        }
        if (cur == 0)
        {
            if (searched[p]) return false;
            searched[p] = true;
        }
        if (trieNodes[cur].endOfWord && search(str, p, 0)) return true;
        if (!trieNodes[cur].nexts[str[p]]) return false;
        return search(str, p + 1, trieNodes[cur].nexts[str[p]]);
    }

    bool wordBreak_DFS(string s, vector<string>& wordDict) {
        initTrieTree();
        for (auto && word : wordDict)
            addToTrieTree(word, 0, 0);
        searched.resize(s.size());
        for (auto & c : searched) c = false;
        return search(s, 0, 0);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //return wordBreak_DFS(s, wordDict);
        initTrieTree();
        for (auto && word : wordDict)
            addToTrieTree(word, 0, 0);
        bool f[s.size() + 1];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 0; i < s.size(); ++i)
            if (f[i])
                for (int j = 0, cur = 0; i + j < s.size();)
                {
                    if (!trieNodes[cur].nexts[s[i + j]])
                        break;
                    cur = trieNodes[cur].nexts[s[i + j]];
                    ++j;
                    if (trieNodes[cur].endOfWord)
                        f[i + j] = true;
                }
        return f[s.size()];
    }
};