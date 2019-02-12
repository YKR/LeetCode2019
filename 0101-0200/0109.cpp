/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(vector<int>& nums, int l, int r)
    {
        if (l == r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode * cur = new TreeNode(nums[mid]);
        cur->left = build(nums, l, mid);
        cur->right = build(nums, mid + 1, r);
        return cur;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (auto ptr = head; ptr; ptr = ptr->next)
            nums.push_back(ptr->val);
        return build(nums, 0, nums.size());
    }
};