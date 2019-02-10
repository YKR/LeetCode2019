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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        vector<pair<int, TreeNode *>> stk;
        stk.push_back(make_pair(0, root));
        while(!stk.empty())
        {
            switch (stk.back().first)
            {
                case 0:
                    ++stk.back().first;
                    if (stk.back().second->left != nullptr)
                        stk.push_back(make_pair(0, stk.back().second->left));
                    break;
                case 1:
                    ++stk.back().first;
                    ans.push_back(stk.back().second->val);
                    if (stk.back().second->right != nullptr)
                        stk.push_back(make_pair(0, stk.back().second->right));
                    break;
                case 2:
                    stk.pop_back();
                    break;
            }
        }
        return ans;
    }
};