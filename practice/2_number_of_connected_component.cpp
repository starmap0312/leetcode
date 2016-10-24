#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    Solution1() {}

    void DFS(int i, vector<vector<int> > &edges, vector<bool> &visited) {
        visited[i] = true;                          // mark node i as visited
        for (int j = 0; j < edges[i].size(); j++) { // traverse all node i's neighbors
            if (edges[i][j] == 1) {
                if (!visited[j]) {                  // if node j is not yet visited
                    DFS(j, edges, visited);         // traverse from node j via DFS recursively
                }
            }
        }
    }

    int countComponent(vector<vector<int> > &edges) {
        int count = 0;                             // number of connected component
        vector<bool> visited(edges.size(), false); // initially, all nodes are unvisited
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {                     // if node i is not yet visited
                DFS(i, edges, visited);            // traverse from node i via DFS
                count++;
            }
        }
        return count;
    }
};

class Node {
public:
    Node() {}

    void add(int nbr) {
        neighbors.push_back(nbr);
    }

    vector<int>& nbrs() {
        return neighbors;
    }

private:
    vector<int> neighbors;
};

class Solution2 {
public:
    Solution2() {}

    void DFS(int i, vector<Node *> &nodes, vector<bool> &visited) {
        visited[i] = true;                          // mark node i as visited
        vector<int> nbrs = nodes[i] -> nbrs();
        for (int j = 0; j < nbrs.size(); j++) {     // traverse all node i's neighbors
            if (!visited[nbrs[j]]) {                // if node nbrs[j] is not yet visited
                DFS(nbrs[j], nodes, visited);       // traverse from node nbrs[j] via DFS recursively
            }
        }
    }
    int countComponent(vector<Node *> &nodes) {
        int count = 0;                             // number of connected component
        vector<bool> visited(nodes.size(), false); // initially, all nodes are unvisited
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {                     // if node i is not yet visited
                DFS(i, nodes, visited);            // traverse from node i via DFS
                count++;
            }
        }
        return count;
    }
};

int main() {
    int a[][5]= {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    //  |-- 1 --|
    //  0       3       4
    //  |-- 2 --|

    cout << "Method 1: adjacency matrix and visited vector" << endl;
    // initialize adjacency matrix: edges
    vector<vector<int> > edges;
    for (int i = 0; i < 5; i++) {
        edges.push_back(vector<int>(a[i], a[i] + 5));
    }
    Solution1 solution1;
    cout << solution1.countComponent(edges) << endl;

    cout << "Method 2: adjacency list and visited vector" << endl;
    // initialize adjacency list: nodes
    vector<Node *> nodes(5, new Node());
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 1) {
                nodes[i] -> add(j);
            }
        }
    }
    Solution2 solution2;
    cout << solution2.countComponent(nodes) << endl;

    return 0;
}
