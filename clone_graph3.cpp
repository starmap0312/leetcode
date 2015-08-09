/* - use breadth-first search to traverse all nodes
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>

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
        queue<UndirectedGraphNode*> q;
        q.push(node);
        set<UndirectedGraphNode*> v = findNodes(q);
        vector<UndirectedGraphNode*> visited(v.begin(), v.end());
        int rc = find(visited.begin(), visited.end(), node) - visited.begin();
        vector<UndirectedGraphNode *> clone = cloneNodes(visited);
        cloneEdges(visited, clone);
        return clone[rc];
        return NULL;
    }
    set<UndirectedGraphNode*> findNodes(queue<UndirectedGraphNode*> &q) {
        set<UndirectedGraphNode*> v;
        while (!q.empty()) {
            UndirectedGraphNode * u = q.front();
            if (v.find(u) == v.end()) {
                v.insert(u);
                for (int i = 0; i < u -> neighbors.size(); i++) {
                   q.push(u -> neighbors[i]);
                }
            }
            q.pop();
        }
        return v;
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
};

int main() {
    return 0;
}
