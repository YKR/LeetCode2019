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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode pseudoHead(0); pseudoHead.next = head;
        ListNode * mth = nullptr, * nth = nullptr;
        ListNode * mthBefore = nullptr, * nthAfter = nullptr;
        int cnt = 0;
        for (auto ptr = & pseudoHead, ptr2 = ptr->next; ptr2 != nullptr;)
        {
            ++cnt;
            if (cnt == m) mth = ptr2, mthBefore = ptr;
            if (cnt == n) nth = ptr2, nthAfter = ptr2->next;
            auto nn = ptr2->next;
            if (cnt > m && cnt <= n) ptr2->next = ptr;
            ptr = ptr2;
            ptr2 = nn;
        }
        mthBefore->next = nth;
        mth->next = nthAfter;
        head = pseudoHead.next;
        return head;
    }
};