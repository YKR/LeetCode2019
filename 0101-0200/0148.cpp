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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode preHead(0); preHead.next = head;
        auto premid = &preHead, rightend = &preHead;
        while (true)
        {
            rightend = rightend->next;
            if (rightend == nullptr) break;
            rightend = rightend->next;
            if (rightend == nullptr) break;
            premid = premid->next;
        }
        auto mid = premid->next;
        premid->next = nullptr;
        auto left = sortList(preHead.next);
        auto right = sortList(mid);
        auto ptr = &preHead;
        auto pleft = left, pright = right;
        while (pleft && pright)
        {
            if (pleft->val < pright->val)
            {
                ptr->next = pleft;
                pleft = pleft->next;
            }
            else
            {
                ptr->next = pright;
                pright = pright->next;
            }
            ptr = ptr->next;
        }
        while (pleft)
        {
            ptr->next = pleft;
            pleft = pleft->next;
            ptr = ptr->next;
        }
        while (pright)
        {
            ptr->next = pright;
            pright = pright->next;
            ptr = ptr->next;
        }
        return preHead.next;
    }
};