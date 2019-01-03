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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
                pq.push(make_pair(lists[i]->val, i));
        }
        ListNode * head = new ListNode(0);
        ListNode * ptr = head;
        while (!pq.empty())
        {
            auto ppp = pq.top(); pq.pop();
            ptr->next = new ListNode(ppp.first);
            ptr = ptr->next;
            lists[ppp.second] = lists[ppp.second]->next;
            if (lists[ppp.second])
                pq.push(make_pair(lists[ppp.second]->val, ppp.second));
        }
        ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
};