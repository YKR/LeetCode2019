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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        for (auto ptr = head; ptr; ptr = ptr->next)
            nodes.push_back(ptr);
        for (int i = 0, j = nodes.size() - 1; i <= j; ++i, --j)
        {
            if (i != 0) nodes[j + 1]->next = nodes[i];
            if (i != j) nodes[i]->next = nodes[j];
            nodes[j]->next = nullptr;
        }
    }
};