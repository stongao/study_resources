// Source : Leetcode https://leetcode.com/problems/clone-graph/
// Date : Thursday, Feb 16
// Time : ~20 min
// Errors : 1. Used wrong function of unordered_map to find entry- find() returns gives iterator, at() return value for key

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
    unordered_map<UndirectedGraphNode *, bool> visited;
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hm;

    UndirectedGraphNode* cloneDFS(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(visited.find(node) == visited.end()) {
            UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
            visited.insert(make_pair(node,false));
            hm.insert(make_pair(node,newNode));
            for(int i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode *newNeighbor = cloneDFS(node->neighbors.at(i));
            }
            return newNode;
        }
        return hm.at(node);
    }
    
    void linkNeighbors(UndirectedGraphNode *node) {
        if(node == NULL) return;
        if(visited.at(node) == true) return;
        else {
            visited.at(node) = true;
            UndirectedGraphNode *newNode = hm.at(node);
            for(vector<UndirectedGraphNode *>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); it++) {
                newNode->neighbors.push_back(hm.at(*it));
            }
            
            for(int i = 0; i < node->neighbors.size(); i++) {
                linkNeighbors(node->neighbors.at(i));
            }
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *newNode = cloneDFS(node);
        linkNeighbors(node);
        return newNode;
    }
};
