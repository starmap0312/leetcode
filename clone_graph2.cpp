/* 
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class UndirectedGraphNode {
public:
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) { };
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        set<UndirectedGraphNode*> v;
        visit(node, v);
        vector<UndirectedGraphNode*> visited(v.begin(), v.end());
        int rc = find(visited.begin(), visited.end(), node) - visited.begin();
        vector<UndirectedGraphNode *> clone = cloneNodes(visited);
        cloneEdges(visited, clone);
        return clone[rc];
    }
    vector<UndirectedGraphNode *> cloneNodes(vector<UndirectedGraphNode*> &visited) {
        vector<UndirectedGraphNode *> clone(visited.size());
        for (int i = 0; i < visited.size(); i++)
            clone[i] = new UndirectedGraphNode(visited[i] -> label);
        return clone;
    }
    void cloneEdges(vector<UndirectedGraphNode*> &visited, vector<UndirectedGraphNode*> &clone) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < (visited[i] -> neighbors).size(); j++) {
                vector<UndirectedGraphNode *>::iterator itr =
                    find(visited.begin(), visited.end(), (visited[i] -> neighbors)[j]);
                int found = itr - visited.begin();
                (clone[i] -> neighbors).push_back(clone[found]);
            }
        }
    }
    void visit(UndirectedGraphNode *node, set<UndirectedGraphNode*> &visited) {
        if (visited.find(node) != visited.end()) return;
        visited.insert(node);
        for (int i = 0; i < (node -> neighbors).size(); i++)
            visit(node -> neighbors[i], visited);
    }
};

int main() {
    return 0;
}
