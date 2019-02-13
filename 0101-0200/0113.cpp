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
    vector<vector<int>> ret;
    vector<int> path;

    void test(TreeNode * cur, int rest)
    {
        if (cur == nullptr) return;
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (cur->val == rest)
            {
                path.push_back(cur->val);
                ret.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(cur->val);
        test(cur->left, rest - cur->val);
        test(cur->right, rest - cur->val);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        test(root, sum);
        return ret;
    }
};