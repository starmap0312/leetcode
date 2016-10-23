/* adjacency list:
 *   vector<Node *> nodes; // a list of nodes
 *   nodes[i].neighbors;   // store the indices of its neighbor nodes
 * ex.
 *   nodes[0] -> neighbors = [1, 2]
 *   nodes[1] -> neighbors = [3]
 *   nodes[2] -> neighbors = [3]
 *   nodes[3] -> neighbors = []
 *
 * use a boolean vector for remembering the visited nodes (visited[i] == true <=> node i is visited)
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
        int next = q.front();                         // pop the next node index from the queue
        q.pop();
        if (!visited[next]) {                         // if the node is not yet visited, mark it as visited
            cout << nodes[next] -> value << " ";
            visited[next] = true;
            vector<int> nbrs = nodes[next] -> neighbors;
            for (int i = 0; i < nbrs.size(); i++) {   // push all its unvisited neighbors to the queue
                if (!visited[nbrs[i]]) {
                    q.push(nbrs[i]);
                }
            }
        }
    }
    cout << endl;
}

void DFS(vector<Node *> &nodes, int start) {
    vector<bool> visited(nodes.size(), false);
    stack<int> q;
    q.push(start);
    while (!q.empty()) {
        int next = q.top();                           // pop the next index from the queue
        q.pop();
        if (!visited[next]) {                         // if the node is not yet visited, mark it as visited
            cout << nodes[next] -> value << " ";
            visited[next] = true;
            vector<int> nbrs = nodes[next] -> neighbors;
            for (int i = 0; i < nbrs.size(); i++) {   // push all its unvisited neighbors to the stack
                if (!visited[nbrs[i]]) {
                    q.push(nbrs[i]);
                }
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
