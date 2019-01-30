class Solution {
public:
    int largestRectangleAreaWithUnionFind(vector<int>& heights)
    {
        if (heights.empty()) return 0;
        int ans = 0;
        int order[heights.size()], uf[heights.size()], ufsize[heights.size()];
        for (int i = 0; i < heights.size(); ++i)
            order[i] = uf[i] = i, ufsize[i] = 1;
        auto orderCompare = [&heights](int a, int b) -> bool {
            return heights[a] > heights[b];
        };
        sort(order, order + heights.size(), orderCompare);
        function<int (int index)> unionFind;
        unionFind = [&uf, &unionFind](int index) -> int {
            if (uf[index] == index) return index;
            return uf[index] = unionFind(uf[index]);
        };
        bool searched[heights.size()];
        memset(searched, 0, sizeof(searched));
        for (int i = 0; i < heights.size(); ++i)
        {
            if (order[i] + 1 < heights.size() && searched[order[i] + 1])
            {
                ufsize[unionFind(order[i] + 1)] += ufsize[unionFind(order[i])];
                uf[unionFind(order[i])] = unionFind(order[i] + 1);
            }
            if (order[i] - 1 >= 0 && searched[order[i] - 1])
            {
                ufsize[unionFind(order[i] - 1)] += ufsize[unionFind(order[i])];
                uf[unionFind(order[i])] = unionFind(order[i] - 1);
            }
            ans = max(ans, heights[order[i]] * ufsize[unionFind(order[i])]);
            searched[order[i]] = true;
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        //return largestRectangleAreaWithUnionFind(heights);
        heights.push_back(0);
        int ans = 0;
        vector<int> heightStack;
        for (int i = 0 ; i < heights.size(); ++i)
        {
            while (!heightStack.empty() && heights[heightStack.back()] >= heights[i])
            {
                int rangeHeightIndex = heightStack.back();
                heightStack.pop_back();
                int beginIndex = heightStack.empty() ? 0 : heightStack.back() + 1;
                ans = max(ans, (i - beginIndex) * heights[rangeHeightIndex]);
            }
            heightStack.push_back(i);
        }
        return ans;
    }
};