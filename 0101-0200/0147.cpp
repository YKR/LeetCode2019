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
    ListNode* insertionSortList(ListNode* head) {
        ListNode preHead(INT_MIN); preHead.next = head;
        auto ptr = &preHead;
        while (true)
        {
            if (ptr->next == nullptr) break;
            auto tmp = ptr->next;
            ptr->next = tmp->next;
            auto findptr = &preHead;
            while (true)
            {
                if (findptr == ptr || findptr->next->val > tmp->val)
                {
                    tmp->next = findptr->next;
                    findptr->next = tmp;
                    break;
                }
                findptr = findptr->next;
            }
            ptr = findptr == ptr ? ptr->next : ptr;
        }
        return preHead.next;
    }
};