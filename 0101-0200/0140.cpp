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

    vector<char> searchResults;
    vector<string> ret;
    string seq;
    bool search(const string & str, int p, int cur)
    {
        if (p == str.size())
        {
            if (trieNodes[cur].endOfWord)
            {
                ret.push_back(seq);
                return true;
            }
            return false;
        }
        if (cur == 0 && searchResults[p] == false) return false;
        int thisResult = false;
        if (trieNodes[cur].endOfWord)
        {
            seq.push_back(' ');
            if (search(str, p, 0))
                thisResult = true;
            seq.pop_back();
        }
        if (!trieNodes[cur].nexts[str[p]])
        {
            if (!thisResult && cur == 0)
                return searchResults[p] = false;
            return thisResult;
        }
        seq.push_back(str[p]);
        thisResult = search(str, p + 1, trieNodes[cur].nexts[str[p]]) || thisResult;
        seq.pop_back();
        if (!thisResult && cur == 0)
            return searchResults[p] = false;
        return thisResult;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        initTrieTree();
        for (auto && word : wordDict)
            addToTrieTree(word, 0, 0);
        searchResults.resize(s.size());
        for (auto & c : searchResults) c = true;
        search(s, 0, 0);
        return ret;
    }
};