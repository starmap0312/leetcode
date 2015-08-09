/* - first depth-first search the graph to obtain the set of all distinct nodes
 *   then create a copy of all distinct nodes and create their edges to neighbors
 */
#include <iostream>
#include <vector>

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
        vector<UndirectedGraphNode*> visited;
        visit(node, visited);
        vector<UndirectedGraphNode *> clone = cloneNodes(visited);
        cloneEdges(visited, clone);
        return clone[0];
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
    vector<UndirectedGraphNode *> cloneNodes(vector<UndirectedGraphNode*> &visited) {
        vector<UndirectedGraphNode *> clone(visited.size());
        for (int i = 0; i < visited.size(); i++)
            clone[i] = new UndirectedGraphNode(visited[i] -> label);
        return clone;
    }
    void visit(UndirectedGraphNode *node, vector<UndirectedGraphNode*> &visited) {
        if (find(visited.begin(), visited.end(), node) != visited.end()) return;
        visited.push_back(node);
        for (int i = 0; i < node -> neighbors.size(); i++) {
            visit(node -> neighbors[i], visited);
        }
    }
};

int main() {
    return 0;
}
