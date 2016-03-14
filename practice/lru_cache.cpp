#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) { }
    Node *prev, *next;
    int key, val;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        if (size == 0 || mp.find(key) == mp.end()) return -1;
        else {
            Node *found = mp[key];
            // update the tail if needed 
            if (found == tail) tail = found -> prev;
            // update the predecessor if any
            if (found -> prev != NULL) {
                (found -> prev) -> next = found -> next;
            }
            // update the successor if any
            if (found -> next != NULL) {
                (found -> next) -> prev = found -> prev;
            }
            // update the head to be the found node
            if (found != head) {
                head -> prev = found;
                found -> next = head, found -> prev = NULL;
                head = found;
            }
            if (head != NULL) {
                cout << "h:" << head -> key << endl;
                if (head -> next != NULL) cout << "t:" << head -> next -> key << endl;
            }
            if (tail != NULL) cout << "tt:" << tail -> key << endl;
            return found -> val;
        }
    }
    
    void set(int key, int value) {
        if (size == 0) return;
        if (mp.find(key) == mp.end()) { // add a new node
            if (head != NULL) {
                cout << "(h:" << head -> key << endl;
                if (head -> next != NULL) cout << "(t:" << head -> next -> key << endl;
            }
            if (tail != NULL)
                cout << "((t:" << tail -> key << endl;
            if (mp.size() == size) { // the nodes exceed the capacity
                // update the head
                if (head == tail) head = NULL;
                if (tail != NULL && tail -> prev != NULL) (tail -> prev) -> next = NULL;
                // remove the tail and update the tail to be the predecessor
                Node *newtail = tail -> prev;
                mp.erase(tail -> key);
                delete tail;
                tail = newtail;
            }
            if (head != NULL) {
                cout << "-h:" << head -> key << endl;
                if (head -> next != NULL) cout << "-t:" << head -> next -> key << endl;
            }
            Node *node = new Node(key, value);
            mp[key] = node;
            if (tail == NULL) tail = node;
            if (head != NULL) cout << "(h:" << head -> key << endl;
            if (head != NULL) {
                head -> prev = node;
                node -> next = head;
            }
            head = node;
        } else { // update an existing node
            Node *node = mp[key];
            node -> val = value;
            get(key);
        }
        if (head != NULL) {
            cout << "h:" << head -> key << endl;
            if (head -> next != NULL) cout << "t:" << head -> next -> key << endl;
        }
    }

private:
    int size;
    map<int, Node*> mp;
    Node *head, *tail;
};

int main() {
    LRUCache cache(2);
    cout << "set(2, 1)" << endl;
    cache.set(2, 1);
    cout << "set(3, 2)" << endl;
    cache.set(3, 2);
    cout << "get(3)" << endl;
    cout << cache.get(3) << endl;
    cout << "get(2)" << endl;
    cout << cache.get(2) << endl;
    cout << "set(4, 3)" << endl;
    cache.set(4, 3);
    cout << "get(2)" << endl;
    cout << cache.get(2) << endl;
    return 0;
}
