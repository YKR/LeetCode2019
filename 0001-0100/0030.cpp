class Solution {
public:

    struct AcTrieNode
    {
        vector<pair<char, int>> next;
        int fail;
        vector<int> wordIndices;
        int length;
        AcTrieNode() : next(), fail(-1), wordIndices(), length(0) {}
        int findNext(char c)
        {
            for (auto && nx : next)
                if (nx.first == c) return nx.second;
            return -1;
        }
    };

    struct AcTrie
    {
        vector<AcTrieNode> nodes;
        AcTrie() : nodes() { nodes.push_back(AcTrieNode()); }
        void insert(string & s, int index)
        {
            int cur = 0;
            for (auto && c : s)
            {
                int nx = nodes[cur].findNext(c);
                if (nx == -1)
                {
                    nodes.push_back(AcTrieNode());
                    nodes[cur].next.push_back(make_pair(c, nodes.size() - 1));
                    nx = nodes.size() - 1;
                }
                cur = nx;
            }
            nodes[cur].wordIndices.push_back(index);
            nodes[cur].length = s.size();
        }
        void buildFails()
        {
            deque<int> que;
            que.push_back(0);
            while (!que.empty())
            {
                int cur = que.front(); que.pop_front();
                for (auto && nxpair : nodes[cur].next)
                {
                    nodes[nxpair.second].fail = 0;
                    for (int curfail = nodes[cur].fail; curfail != -1; curfail = nodes[curfail].fail)
                    {
                        int nx = nodes[curfail].findNext(nxpair.first);
                        if (nx != -1)
                        {
                            nodes[nxpair.second].fail = nx;
                            break;
                        }
                    }
                    que.push_back(nxpair.second);
                }
            }
        }
        vector<pair<int, int>> parse(string & s)
        {
            vector<pair<int, int>> ret;
            int cur = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                int nx;
                do nx = nodes[cur].findNext(s[i]); while (nx == -1 && (cur = nodes[cur].fail) != -1);
                cur = nx;
                if (cur == -1) cur = 0;
                if (!nodes[cur].wordIndices.empty())
                    ret.push_back(make_pair(i, cur));
            }
            return ret;
        }
    };

    AcTrie ac;

    bool verify(vector<pair<int, int>> & matches, vector<string> & words, bool * wordsUsed, int curMatch, int numWordsUsed)
    {
        if (numWordsUsed == words.size()) return true;
        int nxpos = matches[curMatch].first - ac.nodes[matches[curMatch].second].length;
        for (int i = curMatch - 1; i >= 0; --i)
        {
            if (matches[i].first == nxpos)
            {
                for (auto && ind : ac.nodes[matches[i].second].wordIndices)
                {
                    if (!wordsUsed[ind])
                    {
                        wordsUsed[ind] = true;
                        return verify(matches, words, wordsUsed, i, numWordsUsed + 1);
                    }
                }
                return false;
            }
        }
        return false;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return vector<int>();
        if (words[0].empty())
        {
            vector<int> ret;
            for (int i = 0; i <= s.size(); ++i)
                ret.push_back(i);
            return ret;
        }
        vector<int> ret;
        int wordsTotalLength = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            ac.insert(words[i], i);
            wordsTotalLength += words[i].size();
        }
        ac.buildFails();
        vector<pair<int, int>> matches = ac.parse(s);
        bool wordsUsed[words.size()];
        for (int i = words.size() - 1; i < matches.size(); ++i)
        {
            memset(wordsUsed, 0, sizeof(wordsUsed));
            wordsUsed[ac.nodes[matches[i].second].wordIndices[0]] = true;
            if (verify(matches, words, wordsUsed, i, 1))
                ret.push_back(matches[i].first - wordsTotalLength + 1);
        }
        return ret;
    }
};