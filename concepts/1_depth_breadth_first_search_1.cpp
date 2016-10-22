/* adjacency list:
 *   vector<Node *> nodes; // a list of nodes
 *   nodes[i].neighbors;   // store the indices of its neighbor nodes
 * ex.
 *   nodes[0] -> neighbors = [1, 2]
 *   nodes[1] -> neighbors = [3]
 *   nodes[2] -> neighbors = [3]
 *   nodes[3] -> neighbors = []
 *
 * use a boolean vector for recording visited nodes (visited[i] == true <=> node i is visited)
 * - Depth-First Search (DFS): implement the DFS algorithm using a stack (FILO)
 * - Breadth-First Search (BFS): implement the BFS algorithm using a queue (FIFO)
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
    int value;
    vector<int> neighbors;
};

void BFS(vector<Node *> &nodes, int start) {
    vector<bool> visited(nodes.size(), false);
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        if (!visited[index]) {
            cout << nodes[index] -> value << " ";
            visited[index] = true;
        }
        vector<int> nbrs = nodes[index] -> neighbors;
        for (int i = 0; i < nbrs.size(); i++) { // check all the neighbor nodes
            if (!visited[nbrs[i]]) {
                q.push(nbrs[i]);                // push all unvisited neighbor nodes to the queue
            }
        }
    }
    cout << endl;
}

void DFS(vector<Node *> &nodes, int start) {
    stack<int> q;
    q.push(start);
    vector<bool> visited(nodes.size(), false);
    while (!q.empty()) {
        int index = q.top();
        q.pop();
        if (!visited[index]) {
            cout << nodes[index] -> value << " ";
            visited[index] = true;
        }
        vector<int> nbrs = nodes[index] -> neighbors;
        for (int i = 0; i < nbrs.size(); i++) { // check all the neighbor nodes
            if (!visited[nbrs[i]]) {
                q.push(nbrs[i]);                // push the indices of all the unvisited neighbor nodes to the stack 
            }
        }
    }
    cout << endl;
}

int main() {
    vector<Node *> nodes;
    nodes.push_back(new Node(0));
    nodes.push_back(new Node(1));
    nodes.push_back(new Node(2));
    nodes.push_back(new Node(3));
    nodes[0] -> neighbors.push_back(1);
    nodes[0] -> neighbors.push_back(2);
    nodes[1] -> neighbors.push_back(3);
    nodes[2] -> neighbors.push_back(3);
    // nodes[0] -> nodes[1] -> nodes[3]
    //          -> nodes[2] ----|
    cout << "BFS: ";
    BFS(nodes, 0);
    cout << "DFS: ";
    DFS(nodes, 0);
    return 0;
}
