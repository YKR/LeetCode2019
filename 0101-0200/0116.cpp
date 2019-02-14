/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void build(TreeLinkNode * cur, TreeLinkNode * pred, TreeLinkNode * succ)
    {
        if (cur == nullptr) return;
        if (pred != nullptr) pred->next = cur;
        cur->next = succ;
        build(cur->left, pred ? pred->right : nullptr, cur->right);
        build(cur->right, cur->left, succ ? succ->left : nullptr);
    }

    void connect(TreeLinkNode *root) {
        build(root, nullptr, nullptr);
    }
};