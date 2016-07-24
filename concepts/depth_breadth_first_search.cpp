/* 
 * class Node {
 * public:
 *     Node (int v) : value(v) { }
 *     int value;
 *     vector<Node *> neighbors; // adjacency list
 * }; 
 *
 * use a set for recording visited nodes
 *
 * - Depth-First Search (DFS): implement the DFS algorithm using a stack (nodes to be visited)
 *
 *   void DFS(Node *root) {
 *       set<Node*> visited;
 *       stack<Node*> q;
 *       q.push(root);
 *       while (!q.empty()) {      // continue the loop until no more nodes to be visited
 *           Node *node = q.top(); // take one node out from the stack 
 *           q.pop();
 *           vector<Node*> nbrs = node -> neighbors;
 *           for (int i = 0; i < nbrs.size(); i++) {
 *               if (visited.find(nbrs[i]) == visited.end()) { // if the neighbor node is not yet visited
 *                   q.push(nbrs[i]);                          // push the neighbor node to the stack
 *                   visited.insert(nbrs[i]);                  // insert the neighbor node into the visited set
 *               }
 *           }
 *       }
 *   }
 *
 * - Breadth-First Search (BFS): implement the BFS algorithm using a queue (nodes to be visited)
 *
 *   void BFS(Node *root) {
 *       set<Node *> visited;
 *       queue<Node *> q;
 *       q.push(root);
 *       while (!q.empty()) {
 *           Node *node = q.front(); // take one node out from the queue
 *           q.pop();
 *           vector<Node*> nbrs = node -> neighbors;
 *           for (int i = 0; i < nbrs.size(); i++) { // check all the neighbor nodes
 *               if (visited.find(nbrs[i]) == nvisited.end()) { // if the neighbor node is not yet visited
 *                   q.push(nbrs[i]);
 *                   visited.insert(nbrs[i]);
 *               }
 *           }
 *       }
 *   }
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

void BFS(Node *root) {
    set<Node *> visited;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node -> value << " ";
        vector<Node*> nbrs = node -> neighbors;
        // check all the neighbors of node
        for (int i = 0; i < nbrs.size(); i++) {
            // push all unvisited neighbor nodes to the queue 
            if (visited.find(nbrs[i]) == visited.end()) {
                q.push(nbrs[i]);
                visited.insert(nbrs[i]);
            }
        }
    }
    cout << endl;
}

void DFS(Node *root) {
    set<Node *> visited;
    stack<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.top();
        q.pop();
        cout << node -> value << " ";
        vector<Node*> nbrs = node -> neighbors;
        for (int i = 0; i < nbrs.size(); i++) {
            // push all unvisited neighbor nodes to the stack 
            if (visited.find(nbrs[i]) == visited.end()) {
                q.push(nbrs[i]);
                visited.insert(nbrs[i]);
            }
        }
    }
    cout << endl;
}

int main() {
    Node *node1 = new Node(1), *node2 = new Node(2), *node3 = new Node(3), *node4 = new Node(4);
    node1 -> neighbors.push_back(node2);
    node1 -> neighbors.push_back(node3);
    node2 -> neighbors.push_back(node4);
    node3 -> neighbors.push_back(node4);
    // node1 -> node2 -> node4
    //       -> node3 ----|
    DFS(node1);
    BFS(node1);
    return 0;
}
