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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> stk;
        ListNode * pHead = new ListNode(0);
        pHead->next = head;
        ListNode * ptr = pHead;
        ListNode * revptr = pHead;
        while (ptr->next != nullptr)
        {
            stk.clear();
            int cnt;
            for (cnt = 0; cnt < k && ptr->next != nullptr; ++cnt)
                ptr = ptr->next, stk.push_back(ptr);
            if (cnt < k)
                break;
            ListNode * nex = ptr->next;
            for (int i = 1; i < stk.size(); ++i)
                stk[i]->next = stk[i-1];
            stk[0]->next = nex;
            revptr->next = stk[stk.size() - 1];
            revptr = ptr = stk[0];
        }
        head = pHead->next;
        delete pHead;
        return head;
    }
};