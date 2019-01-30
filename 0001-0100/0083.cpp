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
    ListNode* deleteDuplicates(ListNode* head) {
        auto ptr = head;
        while (ptr)
        {
            auto next = ptr->next;
            if (next == nullptr) break;
            if (next->val == ptr->val)
            {
                ptr->next = next->next;
                delete next;
            }
            else ptr = ptr->next;
        }
        return head;
    }
};