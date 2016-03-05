/* - queue (FIFO)
 *
 *     usages:
 *       queue<int> q;
 *
 *     operations:
 *       q.push(4);     // push to the back of the queue
 *       q.pop();       // pop the front element of the queue
 *       q.front();     // return the value of the front element
 *
 *                back            front
 *       push ->    3       2       1   -> pop
 *
 *     while-loop traversal (FIFO):
 *       queue<int> q;
 *       while (q.empty()) {
 *           cout << q.front() << endl;
 *           q.pop();
 *       }
 *
 * - stack (FILO)
 *
 *     usages:
 *       stack<int> s;
 *
 *     operations:
 *       s.push(4);   // push to the top (back) of the stack
 *       s.pop();     // pop the top (back) element of the stack
 *       s.top();     // return the value of the top (back) element
 *
 *                   top/back      bottom/front
 *       push/pop <->   3       2       1
 *
 *     while-loop traversal (FILO):
 *       stack<int> s;
 *       while (s.empty()) {
 *           cout << s.top() << endl;
 *           s.pop();
 *       }
 *
 * - vector (FILO): can simulate a stack and provide traversals from both sides
 *
 *     usages:
 *       vector<int> v;
 *
 *     operations:
 *       v.push_back(4); // push to the back of the vector
 *       v.pop_back();   // pop the back element of the vector
 *       v.front();      // return the value of the front element
 *       v.back();       // return the value of the back element
 *
 *                               back            front
 *       push_back/pop_back <->    3       2       1
 *
 *     while-loop traversal from both sides:
 *       vector<int> v;
 *       for (int i = 0; i < v.size(); i++) {
 *           cout << v[i] << " ";
 *       }
 *
 * - priority_queue: implements maxHeap (default) or minHeap
 *
 *     usages:
 *       priority_queue<int> maxHeap;
 *       priority_queue<int, vector<int>, greater<int> > minHeap;
 *       // a heap of Node pointers with a customized Comparison operator
 *       priority_queue<Node*, vector<Node*>, Comparison> nodeHeap;
 *
 *     operations: (operations are similar to stack)
 *       maxHeap.push(3);  // push value into the heap
 *       maxHeap.pop();    // pop the top element (min/max) from the heap
 *
 * - set: maintain a set of elements, usually used to check if the existence of an
 *        element in the set (ex. a set of visited nodes)
 *
 *     usages:
 *       set<int> s;           // ordered set, s.begin() points to the smallest value
 *       unordered_set<int> s; // unordered set
 *
 *     operations:
 *       s.insert(4);         // insert an element 4 into the set
 *       s.erase(4);          // delete element 4 from the set
 *       s.erase(itr);        // delete the element pointed by itr
 *       s.find(4) == s.end() // find if element 4 is in the set
 *
 *     for-loop traversal:
 *       for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
 *           cout << *itr << " ";
 *       }
 *
 * - hashmap: maintain a set of (key, value) pairs, allowing fast access to value via its key
 *
 *     usages:
 *       map<int, string> mp; // ordered hashmap, mp.begin() points to the smallest key
 *       unordered_map<int, string> mp; // unordered hashmap 
 *
 *     operations:
 *       mp[3] = "three";       // store a pair of (3, "three") into the hashmap
 *       mp.find(3) == v.end(); // find if the key is in the hashmap
 *
 *     for-loop traversal:
 *       for (map<int, string>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
 *           cout << "(" << itr -> first << ", " << itr -> second << ")" << endl;
 *       }
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

class Node {
public:
    Node(int v, int p) : value(v), priority(p) { }
    int value, priority;
};

class Comparison {
public:

    // defines how Node* a will precede Node* b
    // ex. in minHeap, Node* a precedes Node* b <=> a -> priority > b -> priority
    //     Comparison cmp;
    //     cmp(a, b) should return if a precedes b
    bool operator()(Node *a, Node *b) {
        return a -> priority > b -> priority;
    }
};

using namespace std;

int main() {
    // vector
    vector<int> v;
    v.push_back(1), v.push_back(2), v.push_back(3);
    cout << "vector: " << v.back() << " " << v.front() << endl;


    // priority_queue: maxHeap
    priority_queue<int> maxHeap;
    maxHeap.push(3), maxHeap.push(1), maxHeap.push(2);
    cout << "maxHeap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // priority_queue: minHeap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(3), minHeap.push(1), minHeap.push(2);
    cout << "minHeap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    // priority_queue: nodeHeap (a heap of node pointers)
    priority_queue<Node*, vector<Node*>, Comparison> nodeHeap;
    nodeHeap.push(new Node(3, 1));
    nodeHeap.push(new Node(2, 2));
    nodeHeap.push(new Node(1, 3));
    cout << "nodeHeap:" << endl << "(priority, value)" << endl;
    while (!nodeHeap.empty()) {
        Node *node = nodeHeap.top();
        cout << "(" << node -> priority << "," << node -> value << ")" << endl;
        nodeHeap.pop();
    }

    // set
    set<int> s;
    s.insert(3), s.insert(2), s.insert(1);
    cout << "set: ";
    for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // hashmap
    map<int, string> mp;
    mp[2] = "two", mp[3] = "three", mp[1] = "one";
    cout << "hashmap:" << endl;
    for (map<int, string>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
        cout << "(" << itr -> first << ", " << itr -> second << ")" << endl;
    }
    return 0;
}
