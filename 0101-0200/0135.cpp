class Solution {
public:
    int candy_TopologicalSort(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        vector<vector<int>> edges(ratings.size());
        int numInEdges[ratings.size()];
        memset(numInEdges, 0, sizeof(numInEdges));
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
                edges[i - 1].push_back(i),
                ++numInEdges[i];
            else if (ratings[i] < ratings[i - 1])
                edges[i].push_back(i - 1),
                ++numInEdges[i - 1];
        }
        int numCandies[ratings.size()];
        memset(numCandies, 0, sizeof(numCandies));
        int ret = 0;
        deque<int> dq;
        for (int i = 0; i < ratings.size(); ++i)
            if (numInEdges[i] == 0)
                dq.push_back(i);
        while (!dq.empty())
        {
            int cur = dq.front(); dq.pop_front();
            ++numCandies[cur];
            ret += numCandies[cur];
            for (auto && nx : edges[cur])
            {
                numCandies[nx] = max(numCandies[nx], numCandies[cur]);
                --numInEdges[nx];
                if (numInEdges[nx] == 0)
                    dq.push_back(nx);
            }
        }
        return ret;
    }

    int candy_TopoOptimized(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int numCandies[ratings.size()];
        bool fulfilled[ratings.size()];
        memset(numCandies, 0, sizeof(numCandies));
        memset(fulfilled, 0, sizeof(fulfilled));
        deque<int> dq;
        for (int i = 0; i < ratings.size(); ++i)
            if ((i == 0 || ratings[i - 1] >= ratings[i]) && (i == ratings.size() - 1 || ratings[i + 1] >= ratings[i]))
                dq.push_back(i);
        int ans = 0;
        while (!dq.empty())
        {
            int cur = dq.front(); dq.pop_front();
            ans += ++numCandies[cur];
            fulfilled[cur] = true;
            int tar;
            if ((tar = cur - 1) >= 0 && ratings[tar] > ratings[cur] && !fulfilled[tar])
            {
                numCandies[tar] = max(numCandies[tar], numCandies[cur]);
                if ((tar == 0 || fulfilled[tar - 1] || ratings[tar - 1] >= ratings[tar])
                    && (tar == ratings.size() - 1 || fulfilled[tar + 1] || ratings[tar + 1] >= ratings[tar]))
                    dq.push_back(tar);
            }
            if ((tar = cur + 1) < ratings.size() && ratings[tar] > ratings[cur] && !fulfilled[tar])
            {
                numCandies[tar] = max(numCandies[tar], numCandies[cur]);
                if ((tar == 0 || fulfilled[tar - 1] || ratings[tar - 1] >= ratings[tar])
                    && (tar == ratings.size() - 1 || fulfilled[tar + 1] || ratings[tar + 1] >= ratings[tar]))
                    dq.push_back(tar);
            }
        }
        return ans;
    }
    
    int candy(vector<int>& ratings) {
        //return candy_TopologicalSort(ratings);
        //return candy_TopoOptimized(ratings);
        if (ratings.empty()) return 0;
        int arr[ratings.size()];
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1])
                arr[i] = arr[i - 1] + 1;
        int ans = arr[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0 ; --i)
        {
            if (ratings[i] > ratings[i + 1])
                arr[i] = max(arr[i], arr[i + 1] + 1);
            ans += arr[i];
        }
        return ans + ratings.size();
    }
};