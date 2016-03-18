/* - sorting
 *   1) sort an int vector
 *      vector<int> v;
 *      sort(v.begin(), v.end()); // ascending
 *      sort(v.begin(), v.end(), greater<int>()); // descending
 *      i.e. greater<int> cmp;
 *           cmp(a, b) returns true <=> a precedes b
 *           bool precedes(int, int); ==> precedes(a, b) returns true <=> a precedes b
 *      (Note that: priority_queue<int, vector<int>, greater<int> > minHeap;)
 *   2) sort an object vector via a customized function
 *      vector<Node *> nodes;
 *      bool precedes(Node *a, Node *b); // define how Node *a precedes Node *b
 *      sort(nodes.begin(), nodes.end(), precedes);
 */
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node(int k, int v) : key(k), value(v) { }
    int key, value;
};

class Comparison {
public:
    bool operator()(Node *a, Node *b) {
        return (a -> key > b -> key);
    }
};

bool precedes(Node *a, Node *b) {
    return (a -> key > b -> key);
}

int main() {
    // sort a vector in a descending order
    int a[] = { 4, 5, 1, 2, 3};
    vector<int> v(a, a + 5);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    // sort a vector of nodes in a descending order based on their keys
    Node *n[] = { new Node(1, 3), new Node(2, 2), new Node(3, 1) };
    vector<Node *> nodes(n, n + 3);
    sort(nodes.begin(), nodes.end(), precedes);
    for (int i = 0; i < nodes.size(); i++)
        cout << "(" << nodes[i] -> key << ", " << nodes[i] -> value << ") ";
    cout << endl;    
    sort(nodes.begin(), nodes.end(), Comparison());
    for (int i = 0; i < nodes.size(); i++)
        cout << "(" << nodes[i] -> key << ", " << nodes[i] -> value << ") ";
    cout << endl;    
    return 0;
}
