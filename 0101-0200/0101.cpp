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
    bool test(TreeNode * l, TreeNode * r)
    {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;
        return test(l->left, r->right) && test(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return test(root->left, root->right);
    }
};