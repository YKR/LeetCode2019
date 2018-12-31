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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        cur->next = new ListNode(0);
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = cur->next->val + l1->val + l2->val;
            cur->next->val = sum % 10;
            cur->next->next = new ListNode(sum / 10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int sum = cur->next->val + l1->val;
            cur->next->val = sum % 10;
            cur->next->next = new ListNode(sum / 10);
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int sum = cur->next->val + l2->val;
            cur->next->val = sum % 10;
            cur->next->next = new ListNode(sum / 10);
            cur = cur->next;
            l2 = l2->next;
        }
        if (cur->next->val == 0)
        {
            delete cur->next;
            cur->next = nullptr;
        }
        cur = head->next;
        delete head;
        return cur;
    }
};