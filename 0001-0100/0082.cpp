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
        ListNode * preHead = new ListNode(0);
        preHead->next = head;
        auto ptr = preHead;
        while (ptr)
        {
            auto next = ptr->next;
            if (next == nullptr) break;
            auto next2 = next->next;
            if (next2 == nullptr) break;
            if (next->val == next2->val)
            {
                int dupVal = next->val;
                while (ptr->next && ptr->next->val == dupVal)
                {
                    auto tmp = ptr->next;
                    ptr->next = tmp->next;
                    delete tmp;
                }
            }
            else ptr = ptr->next;
        }
        auto ret = preHead->next;
        delete preHead;
        return ret;
    }
};