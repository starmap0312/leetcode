/* representation: adjacency list
 *   nodes[0] -> neighbors
 *   nodes[1] -> neighbors
 *   nodes[2] -> neighbors
 *
 * class Node {
 * public:
 *     Node (int v) : value(v) { }
 *     int value;
 *     vector<int> neighbors;
 * };
 *
 * 2) keep a boolean vector (visited[i] == true iff node i is visited)
 * - Depth-First Search (DFS): implement the DFS algorithm using a stack (nodes to be visited)
 *
 *   void DFS(vector<Node *> &nodes, int root) {
 *       stack<int> q;
 *       vector<bool> visited(nodes.size(), false);
 *       q.push(root);
 *       while (!q.empty()) {             // continue the loop until no more nodes to be visited
 *           int index = q.top(); // take one node out from the stack 
 *           q.pop();
 *           vector<int> nbrs = nodes[index] -> neighbors;
 *           for (int i = 0; i < nbrs.size(); i++) {
 *               if (visited[nbrs[i]] == false) { // if the neighbor node is not yet visited
 *                   q.push(nbrs[i]);             // push the neighbor node to the stack
 *                   visited[nbrs[i]] = true;     // insert the neighbor node into the visited set
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
    int value;
    vector<int> neighbors;
};

void BFS(vector<Node *> &nodes, int root) {
    queue<int> q;
    q.push(root);
    vector<bool> visited(nodes.size(), false);
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        cout << nodes[index] -> value << " ";
        vector<int> nbrs = nodes[index] -> neighbors;
        // check all the neighbors of node
        for (int i = 0; i < nbrs.size(); i++) {
            // push all unvisited neighbor nodes to the queue 
            if (visited[nbrs[i]] == false) {
                q.push(nbrs[i]);
                visited[nbrs[i]] = true;
            }
        }
    }
    cout << endl;
}

void DFS(vector<Node *> &nodes, int root) {
    stack<int> q;
    q.push(root);
    vector<bool> visited(nodes.size(), false);
    while (!q.empty()) {
        int index = q.top();
        q.pop();
        cout << nodes[index] -> value << " ";
        vector<int> nbrs = nodes[index] -> neighbors;
        for (int i = 0; i < nbrs.size(); i++) {
            // push all unvisited neighbor nodes to the stack 
            if (visited[nbrs[i]] == false) {
                q.push(nbrs[i]);
                visited[nbrs[i]] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    vector<Node *> nodes;
    nodes.push_back(new Node(1));
    nodes.push_back(new Node(2));
    nodes.push_back(new Node(3));
    nodes.push_back(new Node(4));
    nodes[0] -> neighbors.push_back(1);
    nodes[0] -> neighbors.push_back(2);
    nodes[1] -> neighbors.push_back(3);
    nodes[2] -> neighbors.push_back(3);
    // nodes[0] -> nodes[1] -> nodes[3]
    //          -> nodes[2] ----|
    DFS(nodes, 0);
    BFS(nodes, 0);
    return 0;
}
