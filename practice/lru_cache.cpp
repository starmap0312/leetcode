/* - use a doubly-linked list and a hashmap to allow quick removal and changes of nodes
 */
#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) { }
    int key, value;
    Node *prev, *next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = tail = NULL;
        size = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node *found = mp[key];
            removeNode(found);
            setHead(found);
            return found -> value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (size == 0) return;
        // if not in the map, create a new node and push it to the head of the list
        if (mp.find(key) == mp.end()) {
            Node *node = new Node(key, value);
            if (mp.size() >= size) {
                mp.erase(tail -> key);
                removeNode(tail);
                //delete tail;
            }
            mp[key] = node;
            setHead(node);
        } else {
        // if in the map, identify the node, update its value, and put it to the head 
            Node *found = mp[key];
            found -> value = value;
            removeNode(found);
            setHead(found);
        }
    }

    void setHead(Node *node) {
        node -> next = head;
        node -> prev = NULL;
        if (head != NULL) head -> prev = node;
        head = node;
        if (tail == NULL) tail = head;
    }

    void removeNode(Node *node) {
        if (node -> prev != NULL) {
            node -> prev -> next = node -> next;
        } else {
            head = node -> next;
        }
        if (node -> next != NULL) {
            node -> next -> prev = node -> prev;
        } else {
            tail = node -> prev;
        }
    }

private:
    int size;
    Node *head, *tail;
    map<int, Node*> mp;
};

int main() {
    LRUCache cache(2);
    cache.set(2, 1);
    cache.set(2, 2);
    cout << "get: " << cache.get(2) << endl;
    cache.set(1, 1);
    cache.set(4, 1);
    cout << "get: " << cache.get(2) << endl;
    return 0;
}
