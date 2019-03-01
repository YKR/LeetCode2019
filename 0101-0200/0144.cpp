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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> stk;
        if (root) stk.push_back(root);
        while (!stk.empty())
        {
            auto cur = stk.back(); stk.pop_back();
            ret.push_back(cur->val);
            if (cur->right) stk.push_back(cur->right);
            if (cur->left) stk.push_back(cur->left);
        }
        return ret;
    }
};