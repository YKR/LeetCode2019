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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ptr, * nth;
        for (ptr = head, nth = head; ptr != nullptr; ptr = ptr->next)
        {
            if (n-- < 0) nth = nth->next;
        }
        if (n == 0)
        {
            head = head->next;
            delete nth;
        }
        else
        {
            ptr = nth->next;
            nth->next = ptr->next;
            delete ptr;
        }
        return head;
    }
};