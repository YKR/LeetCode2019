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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        deque<pair<int, TreeNode*>> bfsq;
        bfsq.push_back(make_pair(0, root));
        while (!bfsq.empty())
        {
            auto cur = bfsq.front(); bfsq.pop_front();
            if (ret.size() <= cur.first) ret.push_back(vector<int>());
            ret.back().push_back(cur.second->val);
            if (cur.second->left) bfsq.push_back(make_pair(cur.first + 1, cur.second->left));
            if (cur.second->right) bfsq.push_back(make_pair(cur.first + 1, cur.second->right));
        }
        return ret;
    }
};