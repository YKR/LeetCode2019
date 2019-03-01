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
    bool hasCycle(ListNode *head) {
        for (auto ptr = head, ptr2 = head; ptr2; ptr = ptr->next)
        {
            if (ptr2->next == nullptr) return false;
            ptr2 = ptr2->next;
            if (ptr2 == ptr) return true;
            if (ptr2->next == nullptr) return false;
            ptr2 = ptr2->next;
            if (ptr2 == ptr) return true;
        }
        return false;
    }
};