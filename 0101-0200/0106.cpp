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
    TreeNode* build(vector<int> & in, vector<int> & post, int il, int ir, int pl, int pr)
    {
        if (il == ir) return nullptr;
        TreeNode * cur = new TreeNode(post[pr - 1]);
        int dpos;
        for (dpos = il; dpos < ir; ++dpos)
            if (in[dpos] == cur->val) break;
        int lsize = dpos - il;
        int rsize = ir - 1 - dpos;
        cur->left = build(in, post, il, dpos, pl, pl + lsize);
        cur->right = build(in, post, dpos + 1, ir, pl + lsize, pr - 1);
        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};