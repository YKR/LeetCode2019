/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode*, RandomListNode*> copyMap;
    RandomListNode *copyRandomList_Map(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        if (copyMap.find(head) != copyMap.end())
            return copyMap[head];
        RandomListNode * copyNode = new RandomListNode(head->label);
        copyMap[head] = copyNode;
        copyNode->next = copyRandomList(head->next);
        copyNode->random = copyRandomList(head->random);
        return copyNode;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        //return copyRandomList_Map(head);
        if (head == nullptr) return nullptr;
        map<RandomListNode*, int> nodeIndices;
        vector<RandomListNode*> copiedNodes;
        int i = 0;
        for (auto ptr = head; ptr; ptr = ptr->next, ++i)
            nodeIndices[ptr] = i,
            copiedNodes.push_back(new RandomListNode(ptr->label));
        i = 0;
        for (auto ptr = head; ptr; ptr = ptr->next, ++i)
        {
            if (i < copiedNodes.size() - 1)
                copiedNodes[i]->next = copiedNodes[i + 1];
            if (ptr->random)
                copiedNodes[i]->random = copiedNodes[nodeIndices[ptr->random]];
        }
        return copiedNodes[0];
    }
};