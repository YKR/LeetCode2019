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
    TreeNode* build(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir)
    {
        if (pl == pr) return nullptr;
        TreeNode* cur = new TreeNode(pre[pl]);
        int inpos = -1;
        for (int i = il; i < ir; ++i)
            if (in[i] == pre[pl])
            {
                inpos = i;
                break;
            }
        int lsize = inpos - il;
        int rsize = ir - inpos - 1;
        cur->left = build(pre, in, pl + 1, pl + 1 + lsize, il, inpos);
        cur->right = build(pre, in, pl + 1 + lsize, pr, inpos + 1, ir);
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};