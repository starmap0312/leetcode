/* - sorting
 *   example 1) sort a vector of integers
 *     vector<int> v;
 *     sort(v.begin(), v.end());                 // in an ascending order (default)
 *     sort(v.begin(), v.end(), greater<int>()); // in a descending order
 *     a) pass in a callbable "object"
 *        ex. greater<int> cmp;
 *            cmp(a, b) returns true <=> a > b (a precedes b)
 *     b) pass in a method "object"
 *        ex. bool precedes(int, int);
 *            precedes(a, b) returns true <=> a > b (a precedes b)
 *     c) Note: the construction of a minHeap needs a callable object "type" as parameter
 *        i.e. priority_queue<int, vector<int>, greater<int> > minHeap;
 *             (key a precedes key b <=> a > b)
 *             priority_queue<int> maxHeap; (default: key a precedes key b <=> a < b)
 *
 *   example 2) sort a vector of objects
 *     vector<Node *> nodes;
 *     bool precedes(Node *a, Node *b); // define how Node *a precedes Node *b
 *     sort(nodes.begin(), nodes.end(), precedes);
 *
 * - find element in vector / set
 *   example:
 *     vector<int> v;
 *     find(v.begin(), v.end(), key) // find() returns v.end() if no key found
 *     set<int> s;
 *     find(s.begin(), s.end(), key) // find key in a set takes O(log n)
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
    Node(int k, int v) : key(k), value(v) { }
    int key, value;
};

// Sorting objects:
// Method 1: pass in a callable object for deciding the precedences of objects
// ex.
//   Precedence precedence;
//   sort(nodes.begin(), nodes.end(), precedence);
class Precedence {
public:
    bool operator()(Node *a, Node *b) { // precedence(a, b) returns true <==> a -> key > b-> key
        return (a -> key > b -> key);
    }
};

// Method 2: pass in a precedes() method for deciding the precedences of objects
// ex.
//   sort(nodes.begin(), nodes.end(), precedes);
bool precedes(Node *a, Node *b) { // precedes(a, b) returns true <==> a -> key > b-> key
    return (a -> key > b -> key);
}

int main() {
    // example 1: sorting a vector of numbers in an ascending order (default: a < b)
    int a[] = { 4, 5, 1, 2, 3 };
    vector<int> v(a, a + 5);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // example 2: sorting a vector of numbers in a descending order (default: a > b)
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // example 3: sorting a vector of nodes in a descending order of keys
    Node *n[] = { new Node(1, 3), new Node(2, 2), new Node(3, 1) };
    vector<Node *> nodes(n, n + 3);
    sort(nodes.begin(), nodes.end(), precedes); // precedes(a, b) == true <=> a -> key > b -> key
    for (int i = 0; i < nodes.size(); i++)
        cout << "(" << nodes[i] -> key << ", " << nodes[i] -> value << ") ";
    cout << endl;    
    sort(nodes.begin(), nodes.end(), Precedence()); // Precedence()(a, b) == true <=> a -> key > b -> key
    for (int i = 0; i < nodes.size(); i++)
        cout << "(" << nodes[i] -> key << ", " << nodes[i] -> value << ") ";
    cout << endl;    

    // example 4: find key in a vector
    int b[] = { 3, 5, 1, 7, 9 };
    vector<int> u(b, b + 5);
    vector<int>::iterator itr = find(u.begin(), u.end(), 7);
    if (itr != u.end()) {
        cout << "Found: " << *itr << endl;
    }
    itr = find(u.begin(), u.end(), 2);
    if (itr == u.end()) {
        cout << "No key found" << endl;
    }

    // example 5: find key in a set 
    set<int> s;
    s.insert(5); s.insert(4); s.insert(1); s.insert(2);
    set<int>::iterator itr2 = find(s.begin(), s.end(), 2);
    if (itr2 != s.end()) {
        cout << "Found: " << *itr2 << endl;
    }
    itr2 = find(s.begin(), s.end(), 3);
    if (itr2 == s.end()) {
        cout << "No key found" << endl;
    }

    // example 6: sort chars of a C++-string
    string word = "cdeeabc";
    sort(word.begin(), word.end());
    cout << word << endl;
    return 0;
}
