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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * ptr = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                ptr->next = new ListNode(l1->val);
                ptr = ptr->next;
                l1 = l1->next;
            }
            else
            {
                ptr->next = new ListNode(l2->val);
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        while (l1 != nullptr)
        {
            ptr->next = new ListNode(l1->val);
            ptr = ptr->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            ptr->next = new ListNode(l2->val);
            ptr = ptr->next;
            l2 = l2->next;
        }
        ListNode * tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};