/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        if (nodeMap.find(node) != nodeMap.end())
            return nodeMap[node];
        auto ret = new UndirectedGraphNode(node->label);
        nodeMap[node] = ret;
        for (auto && neigh : node->neighbors)
            ret->neighbors.push_back(cloneGraph(neigh));
        return ret;
    }
};