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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*> nodes;
        for (auto i = head; i != nullptr; i = i->next)
            nodes.push_back(i);
        if (nodes.empty()) return nullptr;
        k %= nodes.size();
        if (k == 0) return head;
        nodes.back()->next = nodes[0];
        nodes[nodes.size() - k - 1]->next = nullptr;
        return nodes[nodes.size() - k];
    }
};