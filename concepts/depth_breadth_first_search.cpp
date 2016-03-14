/* - Depth-First Search (DFS): implement the DFS algorithm using a stack
 *
 *   void DFS(set<Node*> &remaining, Node *root) {
 *       stack<Node*> q;
 *       q.push(root);
 *       remaining.erase(root);
 *       while (!q.empty()) {
 *           Node *node = q.top();
 *           q.pop();
 *           vector<Node*> nbrs = node -> neighbors;
 *           for (vector<Node*>::iterator itr = nbrs.begin(); itr != nbrs.end(); itr++) {
 *               if (remaining.find(*itr) != remaining.end()) {
 *                   q.push(*itr);
 *                   remaining.erase(*itr);
 *               }
 *           }
 *       }
 *   }
 *
 * - Breadth-First Search (BFS): implement the BFS algorithm using a queue
 *
 *   void BFS(set<Node *> &remaining, Node *root) {
 *       queue<Node *> q;
 *       q.push(root);
 *       remaining.erase(root);
 *       while (!q.empty()) {
 *           Node *node = q.front();
 *           q.pop();
 *           // check all the neighbors of node
 *           vector<Node*> nbrs = node -> neighbors;
 *           for (vector<Node*>::iterator itr = nbrs.begin(); itr != nbrs.end(); itr++) {
 *               if (remaining.find(*itr) != remaining.end()) {
 *                   // the neighbor pointed by itr has not been visited
 *                   q.push(*itr);
 *                   remaining.erase(*itr);
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

void BFS(set<Node *> remaining, Node *root) {
    queue<Node *> q;
    q.push(root);
    remaining.erase(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node -> value << " ";
        vector<Node*> nbrs = node -> neighbors;
        // check all the neighbors of node
        for (vector<Node*>::iterator itr = nbrs.begin(); itr != nbrs.end(); itr++) {
            // push all the neighbors of *itr that have not been visited
            if (remaining.find(*itr) != remaining.end()) {
                q.push(*itr);
                remaining.erase(*itr);
            }
        }
    }
    cout << endl;
}

void DFS(set<Node *> remaining, Node *root) {
    stack<Node*> q;
    q.push(root);
    remaining.erase(root);
    while (!q.empty()) {
        Node *node = q.top();
        q.pop();
        cout << node -> value << " ";
        vector<Node*> nbrs = node -> neighbors;
        for (vector<Node*>::iterator itr = nbrs.begin(); itr != nbrs.end(); itr++) {
            if (remaining.find(*itr) != remaining.end()) {
                q.push(*itr);
                remaining.erase(*itr);
            }
        }
    }
    cout << endl;
}

int main() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1 -> neighbors.push_back(node2);
    node1 -> neighbors.push_back(node3);
    node2 -> neighbors.push_back(node4);
    node3 -> neighbors.push_back(node4);
    Node *root = node1;
    set<Node*> remaining;
    remaining.insert(node1);
    remaining.insert(node2);
    remaining.insert(node3);
    remaining.insert(node4);
    BFS(remaining, root);
    DFS(remaining, root);
    return 0;
}
