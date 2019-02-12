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

    int countLevel(TreeNode * cur)
    {
        if (cur == nullptr) return 0;
        return max(countLevel(cur->left), countLevel(cur->right)) + 1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        int numLevels = countLevel(root);
        vector<vector<int>> ret(numLevels);
        deque<pair<int, TreeNode*>> dq;
        dq.push_back(make_pair(0, root));
        while (!dq.empty())
        {
            auto cur = dq.front(); dq.pop_front();
            ret[numLevels - cur.first - 1].push_back(cur.second->val);
            if (cur.second->left) dq.push_back(make_pair(cur.first + 1, cur.second->left));
            if (cur.second->right) dq.push_back(make_pair(cur.first + 1, cur.second->right));
        }
        return ret;
    }
};