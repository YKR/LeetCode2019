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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        auto left = root->left;
        auto right = root->right;
        root->left = nullptr;
        flatten(left);
        root->right = left;
        auto ptr = root;
        for (; ptr->right != nullptr; ptr = ptr->right);
        flatten(right);
        ptr->right = right;
    }
};