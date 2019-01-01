class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        vector<pair<int,int>> sortedH;
        sortedH.reserve(height.size());
        for (int i = 0; i < height.size(); ++i)
            sortedH.push_back(make_pair(height[i], i));
        sort(sortedH.begin(), sortedH.end(), greater<pair<int,int>>());
        int maxIndex = sortedH[0].second;
        int minIndex = sortedH[0].second;
        for (int i = 1; i < sortedH.size(); ++i)
        {
            maxIndex = max(maxIndex, sortedH[i].second);
            minIndex = min(minIndex, sortedH[i].second);
            int area = sortedH[i].first * (maxIndex - minIndex); 
            if (ret < area)
                ret = area;
        }
        return ret;
    }
};