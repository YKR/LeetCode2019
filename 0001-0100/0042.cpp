class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        vector<int> trapped(height.size());
        for (int i = 0, curHeight = 0; i < height.size(); ++i)
        {
            trapped[i] = max(curHeight - height[i], 0);
            curHeight = max(curHeight, height[i]);
        }
        for (int i = height.size() - 1, curHeight = 0; i >= 0; --i)
        {
            trapped[i] = min(max(curHeight - height[i], 0), trapped[i]);
            curHeight = max(curHeight, height[i]);
            ret += trapped[i];
        }
        return ret;
    }
};