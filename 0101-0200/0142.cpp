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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        auto ptr = head, ptr2 = head;
        for (; ptr2; ptr = ptr->next)
        {
            if (ptr2->next == nullptr) return nullptr;
            ptr2 = ptr2->next;
            if (ptr2 == ptr) break;
            if (ptr2->next == nullptr) return nullptr;
            ptr2 = ptr2->next;
            if (ptr2 == ptr) break;
        }
        int length = 1;
        for (ptr2 = ptr2->next; ptr2 != ptr; ptr2 = ptr2->next) ++length;
        ptr = ptr2 = head;
        for (int i = 0; i < length; ++i) ptr2 = ptr2->next;
        for (; ptr2 != ptr; ptr = ptr->next, ptr2 = ptr2->next);
        return ptr;
    }
};