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
    int ret;
    void sums(TreeNode * node, int cur)
    {
        if (node == nullptr) return;
        cur = cur * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            ret += cur;
            return;
        }
        sums(node->left, cur);
        sums(node->right, cur);
    }

    int sumNumbers(TreeNode* root) {
        ret = 0;
        sums(root, 0);
        return ret;
    }
};