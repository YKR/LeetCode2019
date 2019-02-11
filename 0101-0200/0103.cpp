/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        deque<TreeNode*> dq[2];
        int curdq = 0;
        dq[curdq].push_back(root);
        while (!dq[curdq].empty())
        {
            ret.push_back(vector<int>());
            while (!dq[curdq].empty())
            {
                auto cur = dq[curdq].back(); dq[curdq].pop_back();
                ret.back().push_back(cur->val);
                if (cur->left && curdq == 0) dq[1 ^ curdq].push_back(cur->left);
                if (cur->right) dq[1 ^ curdq].push_back(cur->right);
                if (cur->left && curdq == 1) dq[1 ^ curdq].push_back(cur->left);
            }
            curdq = 1 ^ curdq;
        }
        return ret;
    }
};