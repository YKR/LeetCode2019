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
    ListNode* partition(ListNode* head, int x) {
        ListNode * lh = new ListNode(0), * rh = new ListNode(0);
        ListNode * lp = lh, * rp = rh;
        for (ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            if (ptr->val < x) lp->next = new ListNode(ptr->val), lp = lp->next;
            else rp->next = new ListNode(ptr->val), rp = rp->next;
        }
        lp->next = rh->next;
        ListNode * ret = lh->next;
        delete lh; delete rh;
        return ret;
    }
};