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
    int test(TreeNode * cur)
    {
        if (cur == nullptr) return 0;
        int l = test(cur->left);
        if (l < 0) return -1;
        int r = test(cur->right);
        if (r < 0) return -1;
        if (abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return test(root) >= 0;
    }
};