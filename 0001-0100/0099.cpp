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
    TreeNode * closest;
    vector<TreeNode*> oddNodes;
    void sch(TreeNode* cur)
    {
        if (cur->left)
            sch(cur->left);
        if (!oddNodes.empty() && cur->val < oddNodes[1]->val)
        {
            oddNodes[1] = cur;
        }
        else if (closest && closest->val > cur->val)
        {
            oddNodes.push_back(closest);
            oddNodes.push_back(cur);
        }
        closest = cur;
        if (cur->right)
            sch(cur->right);
    }

    void recoverTree(TreeNode* root) {
        closest = nullptr;
        sch(root);
        swap(oddNodes[0]->val, oddNodes[1]->val);
    }
};