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
    vector<vector<TreeNode*>> ans;
    TreeNode * clone(TreeNode * cur, int baseOffset)
    {
        if (cur == nullptr) return nullptr;
        auto ret = new TreeNode(cur->val + baseOffset);
        if (cur->left) ret->left = clone(cur->left, baseOffset);
        if (cur->right) ret->right = clone(cur->right, baseOffset);
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        ans.push_back(vector<TreeNode*>());
        ans[0].push_back(nullptr);
        ans.push_back(vector<TreeNode*>());
        ans[1].push_back(new TreeNode(1));
        for (int i = 2; i <= n; ++i)
        {
            ans.push_back(vector<TreeNode*>());
            for (int j = 0; j < i; ++j)
            {
                // left: j; right: i - 1 - j
                for (int k = 0; k < ans[j].size(); ++k)
                    for (int l = 0; l < ans[i - 1 - j].size(); ++l)
                    {
                        ans[i].push_back(new TreeNode(j + 1));
                        ans[i].back()->left = clone(ans[j][k], 0);
                        ans[i].back()->right = clone(ans[i - 1 - j][l], j + 1);
                    }
            }
        }
        return ans[n];
    }
};