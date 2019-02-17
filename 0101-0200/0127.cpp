class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord)
        {
            return 1;
        }
        int endIndex = -1;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (endWord == wordList[i])
            {
                endIndex = i;
                break;
            }
        }
        if (endIndex == -1) return 0;
        wordList.push_back(beginWord);
        auto strDiff = [&wordList](int a, int b) -> int {
            int ret = 0;
            for (int i = 0; i < wordList[a].size(); ++i)
                if (wordList[a][i] != wordList[b][i])
                    ++ret;
            return ret;
        };
        vector<vector<int>> nexts(wordList.size());
        for (int i = 0; i < wordList.size(); ++i)
            for (int j = i + 1; j < wordList.size(); ++j)
                if (strDiff(i, j) == 1)
                    nexts[i].push_back(j),
                    nexts[j].push_back(i);
        // MinDist - BFS
        vector<int> minDist(wordList.size());
        deque<int> dq;
        vector<bool> inq(wordList.size());
        for (int i = 0; i < wordList.size(); ++i)
            minDist[i] = INT_MAX, inq[i] = false;
        minDist[wordList.size() - 1] = 0;
        dq.push_back(wordList.size() - 1);
        inq[wordList.size() - 1] = true;
        while (!dq.empty())
        {
            int cur = dq.front(); dq.pop_front();
            for (auto nx : nexts[cur])
                if (minDist[nx] > minDist[cur] + 1)
                {
                    minDist[nx] = minDist[cur] + 1;
                    if (!inq[nx])
                    {
                        dq.push_back(nx);
                        inq[nx] = true;
                    }
                }
            inq[cur] = false;
        }
        return minDist[endIndex] == INT_MAX ? 0 : minDist[endIndex] + 1;
    }
};