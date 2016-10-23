/* - use a doubly-linked list: (removal of a node from the list is easy)
 *   ex.
 *     3 <-> (1) <-> 2 <-> 4  --> to remove 1 from the list
 *     3 <-> 2 <-> 4
 * - use a hashmap to allow quickly locates a node in the list 
 *     3  <->  2  <->  4   --> nodes
 *     |       |       |
 *     |       |       |
 *   mp[3]   mp[2]   mp[4] --> hashmap: maps key to nodes
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
        if (mp.find(key) != mp.end()) { // if key is found in hashmap, remove the node from the list and re-insert to head
            Node *found = mp[key];
            removeNode(found);
            setHead(found);
            return found -> value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (size == 0) return;
        if (mp.find(key) == mp.end()) { // if key is not found in hashmap, insert the key to hashmap and the node to the list head
            Node *node = new Node(key, value);
            if (mp.size() >= size) {    // if the cache is full, remove the list tail before the insertion
                mp.erase(tail -> key);
                removeNode(tail);
            }
            mp[key] = node;
            setHead(node);
        } else {                        // if key is found in hashmap, remove the node from the list and re-insert to the head
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
