/* - queue (FIFO)
 *
 *     usages:
 *       queue<int> q;
 *
 *     operations:
 *       q.push(4);     // push to the back of the queue
 *       q.pop();       // pop the front element of the queue
 *       q.front();     // return the value of the front element
 *       q.empty();     // check if the queue is empty
 *
 *                     back           front
 *       push ----->    3       2       1   -----> pop
 *
 *     while-loop traversal (FIFO):
 *       queue<int> q;
 *       while (!q.empty()) {
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
 *       s.empty();   // check if the stack is empty
 *
 *         <------ push/pop
 *       3 -> top
 *       2
 *       1 -> bottom
 *
 *     while-loop traversal (FILO):
 *       stack<int> s;
 *       while (!s.empty()) {
 *           cout << s.top() << endl;
 *           s.pop();
 *       }
 *
 * - vector (FILO): simulating a stack and providing traversals from both sides
 *
 *     usages:
 *       vector<int> v;
 *
 *     operations:
 *       v.push_back(4); // push to the back of the vector
 *       v.pop_back();   // pop the back element of the vector
 *       v.front();      // return the value of the front element
 *       v.back();       // return the value of the back element
 *       v.empty();      // check if the vector is empty
 *
 *                               back           front
 *   push_back/pop_back ----->    3       2       1   -----> front
 *
 *     while-loop traversal from both sides:
 *       vector<int> v;
 *       for (int i = 0; i < v.size(); i++) {
 *           cout << v[i] << " ";
 *       }
 *
 *       vector<int> v;
 *       for (int i = v.size() - 1; i >= 0; i--) {
 *           cout << v[i] << " ";
 *       }
 *
 *     concatenation: append one vector to the end of the other 
 *       vector<int> v1, v2;
 *       v1.insert(v1.end(), v2.begin(), v2.end());
 *
 *     insertion: insert a value into a vector
 *       vector<int> v;
 *       v.insert(v.begin() + i, value);  // insert value into the i-th position of the vector
 *
 *     initialization:
 *       vector<bool> v(10, false);
 *       vector<int> u;
 *       u = vector<int>(10, 0);
 *
 * - priority_queue: implements maxHeap (default) or minHeap
 *
 *     usages:
 *       priority_queue<int> maxHeap;                             // maxHeap (default)
 *       priority_queue<int, vector<int>, greater<int> > minHeap; // minHeap
 *       // a heap of Node pointers with a Precedence callable class (customized precedences) 
 *       priority_queue<Node*, vector<Node*>, Precedence> nodeHeap;
 *
 *     operations: (operations are similar to stack)
 *       maxHeap.push(3);  // push value into the heap
 *       maxHeap.pop();    // pop the top element max from the heap
 *       maxHeap.top();    // return the value of the top element (min/max)
 *       maxHeap.empty();  // check if the priority_queue is empty
 *
 *     ex. maxHeap
 *
 *         5    -> top  <------ pop
 *      
 *       4   3  -> buttom       (values 3 & 4 precedes value 5)
 *
 *     while-loop traversal: (pop the elements in a asending order: minHeap)
 *       while (!minHeap.empty()) {
 *           cout << minHeap.top() << " ";
 *           minHeap.pop();
 *       }
 *
 * - set: maintain a set of elements, usually used to check if the existence of an element in the set
 *        (ex. a set of visited nodes)
 *
 *     usages:
 *       set<int> s;           // ordered set, s.begin() points to the smallest value
 *       unordered_set<int> s; // unordered set (better performance if order is not important)
 *
 *     operations:
 *       s.insert(4);         // insert an element 4 into the set
 *       s.erase(4);          // delete element 4 from the set
 *       s.erase(itr);        // delete the element pointed by itr
 *       s.find(4) == s.end() // find if element 4 is in the set
 *       s.empty();           // check if the set is empty
 *
 *     for-loop traversal:
 *       for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
 *           cout << *itr << " ";
 *       }
 *
 *     set comparison: (element-wise comparison)
 *       set<int> s1, s2;
 *       (s1 == s2)           // true <=> s1 and s2 contain identical elements
 *
 * - hashmap: maintain a set of (key, value) pairs, allowing fast access to value via its key
 *
 *     usages:
 *       map<int, string> mp;           // ordered hashmap, mp.begin() points to the element with the smallest key
 *       unordered_map<int, string> mp; // unordered hashmap 
 *
 *     operations:
 *       mp[3] = "three";       // insert a pair of (3, "three") into the hashmap
 *       mp.erase(4);           // delete element with key 4 from the hashmap
 *       mp.erase(itr);         // delete the element pointed by itr
 *       mp.find(3) == v.end(); // find if the key is in the hashmap
 *       itr -> first;          // the key of the element pointed by itr
 *       itr -> second;         // the value of the element pointed by itr
 *       mp.empty();            // check if the hashmap is empty
 *
 *     for-loop traversal:
 *       for (map<int, string>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
 *           cout << "(" << itr -> first << ", " << itr -> second << ")" << endl;
 *       }
 *
 *     hashmap comparison: (element-wise comparison)
 *       map<int, string> mp1, mp2;
 *       (mp1 == mp2)           // true <=> mp1 and mp2 have the same (key, value) pairs
 *
 * - string
 *
 *     usages:
 *       string str = "0123456789";
 *
 *     operations:
 *       str.find('3', 3);          // find if 'a' appears in suffix str[3...]
 *       str.find("456", 3);        // find if "abc" appears in suffix str[3...], str.find("abc", 3) == string::npos if not found
 *       str.substr(i, len);        // create a substring of str[i...i + len - 1]
 *       str.c_str();               // convert into a C-style string
 *
 * - pair
 *
 *     usages:
 *
 *       pair<int, string> p;       // to accesss, use p.first, p.second
 *
 *     operations:
 *
 *       pair<int, string> p(3, "012"); 
 *       pair<int, string> p = make_pair(3, "012");
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class Node {
public:
    Node(int v, int p) : value(v), priority(p) { }
    int value, priority;
};

class Precedence { // a callable class for the precedences of Node objects
public:
    // defines how Node* a precedes Node* b
    //   Precedence precedence;
    //     precedence(a, b) should return if a precedes b
    //   ex. in minHeap, Node* a precedes Node* b <=> a -> priority > b -> priority
    bool operator()(Node *a, Node *b) {
        return a -> priority > b -> priority;
    }
};

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

    // priority_queue: minHeap (key a precedes key b <=> key a greater than key b) 
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(3), minHeap.push(1), minHeap.push(2);
    cout << "minHeap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    // priority_queue: a heap of node pointers
    //   need a callable class for deciding the precedences of node pointers
    priority_queue<Node*, vector<Node*>, Precedence> nodeHeap; // minHeap based on node priority
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

    // compare two sets
    set<int> s1, s2;
    s1.insert(1), s1.insert(3);
    s2.insert(3), s2.insert(1);
    // (s1 == s2) is true if and only if the two sets contain identical elements
    cout << (s1 == s2) << endl;

    // hashmap
    map<int, string> mp;
    mp[2] = "two", mp[3] = "three", mp[1] = "one";
    cout << "hashmap:" << endl;
    for (map<int, string>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
        cout << "(" << itr -> first << ", " << itr -> second << ")" << endl;
    }

    // compare two hashmaps
    map<int, string> mp1, mp2;
    mp1[1] = "one", mp1[2] = "two";
    mp2[2] = "two", mp2[1] = "one";
    // (s1 == s2) is true if and only if the two hashmaps have the same (key, value) pairs 
    cout << (mp1 == mp2) << endl;

    // find substring
    string str = "0123456789";
    int pos = str.find("456", 2);
    cout << "Found 456 at position: " << pos << endl;
    pos = str.find("456", 5);
    cout << "No substring found: " << pos << endl;

    // pair
    pair<int, string> p1(3, "012"); 
    pair<int, string> p2 = make_pair(3, "012");
    cout << "(" << p1.first << ", " << p1.second << ")" << endl;
    cout << "(" << p2.first << ", " << p2.second << ")" << endl;
    return 0;
}
