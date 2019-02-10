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
    bool validate(TreeNode * cur, pair<int, int> & lr)
    {
        pair<int, int> sublr;
        if (cur->left)
        {
            if (!validate(cur->left, sublr)) return false;
            if (sublr.second >= cur->val) return false;
            lr.first = sublr.first;
        }
        else lr.first = cur->val;
        if (cur->right)
        {
            if (!validate(cur->right, sublr)) return false;
            if (sublr.first <= cur->val) return false;
            lr.second = sublr.second;
        }
        else lr.second = cur->val;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        pair<int, int> lr;
        return validate(root, lr);
    }
};