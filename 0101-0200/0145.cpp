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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> revAns;
        vector<TreeNode*> stk;
        if (root) stk.push_back(root);
        while (!stk.empty())
        {
            auto cur = stk.back(); stk.pop_back();
            revAns.push_back(cur->val);
            if (cur->left) stk.push_back(cur->left);
            if (cur->right) stk.push_back(cur->right);
        }
        for (int i = 0; i < revAns.size() / 2; ++i)
            swap(revAns[i], revAns[revAns.size() - 1 - i]);
        return revAns;
    }
};