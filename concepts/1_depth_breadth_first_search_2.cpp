/* 
 * use a set for recording visited nodes
 * - Depth-First Search (DFS): implement the DFS algorithm using a stack (nodes to be visited)
 * - Breadth-First Search (BFS): implement the BFS algorithm using a queue (nodes to be visited)
 *
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    Node (int v) : value(v) { }
    vector<Node*> neighbors;
    int value;
};

void BFS(Node *start) {
    set<Node *> visited;
    queue<Node *> q;
    q.push(start);
    while (!q.empty()) {
        Node *node = q.front();                           // pop the next node from the queue
        q.pop();
        if (visited.find(node) == visited.end()) {        // if the node is not yet visited, mark it as visited
            cout << node -> value << " ";
            visited.insert(node);
            vector<Node*> nbrs = node -> neighbors;
            for (int i = 0; i < nbrs.size(); i++) {       // push all its unvisited neighbors to the queue
                if (visited.find(nbrs[i]) == visited.end()) {
                    q.push(nbrs[i]);
                }
            }
        }
    }
    cout << endl;
}

void DFS(Node *start) {
    set<Node *> visited;
    stack<Node*> q;
    q.push(start);
    while (!q.empty()) {
        Node *node = q.top();                             // pop the next node from the stack
        q.pop();
        if (visited.find(node) == visited.end()) {        // if the node is not yet visited, mark it as visited
            cout << node -> value << " ";
            visited.insert(node);
            vector<Node*> nbrs = node -> neighbors;
            for (int i = 0; i < nbrs.size(); i++) {       // push all its unvisited neighbors to the stack
                if (visited.find(nbrs[i]) == visited.end()) {
                    q.push(nbrs[i]);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    Node *node0 = new Node(0), *node1 = new Node(1), *node2 = new Node(2), *node3 = new Node(3);
    node0 -> neighbors.push_back(node1);
    node0 -> neighbors.push_back(node2);
    node1 -> neighbors.push_back(node3);
    node2 -> neighbors.push_back(node3);
    // node0 -> node1 -> node3
    //       -> node2 ----|
    cout << "BFS: ";
    BFS(node0);
    cout << "DFS: ";
    DFS(node0);
    return 0;
}
