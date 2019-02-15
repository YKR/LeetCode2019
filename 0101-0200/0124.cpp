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
    int ans;
    int maxSinglePath(TreeNode* cur)
    {
        if (cur == nullptr) return 0;
        int left = maxSinglePath(cur->left);
        int right = maxSinglePath(cur->right);
        int ret = max(cur->val, max(cur->val + left, cur->val + right));
        ans = max(ans, max(ret, left + right + cur->val));
        return ret;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxSinglePath(root);
        return ans;
    }
};