/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * ptr, * rtp;
        ptr = head;
        if (ptr) rtp = ptr->next;
        while (ptr && rtp)
        {
            swap(ptr->val, rtp->val);
            ptr = rtp->next;
            if (ptr) rtp = ptr->next;
        }
        return head;
    }
};