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
    TreeLinkNode * findNearestChild(TreeLinkNode * parent)
    {
        for (auto ptr = parent; ptr != nullptr; ptr = ptr->next)
        {
            if (ptr->left) return ptr->left;
            if (ptr->right) return ptr->right;
        }
        return nullptr;
    }

    void build(TreeLinkNode * cur, TreeLinkNode * parent)
    {
        if (cur == nullptr) return;
        if (parent)
        {
            if (cur == parent->left && parent->right)
                cur->next = parent->right;
            else
                cur->next = findNearestChild(parent->next);
        }
        build(cur->right, cur);
        build(cur->left, cur);
    }

    void connect(TreeLinkNode *root) {
        build(root, nullptr);
    }
};