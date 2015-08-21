/* - use doubly-linked list to keep the recently used elements
 *   ex.        head                tail
 *       key      4   -->   2   -->   1
 *       value    1   <--   3   <--   1
 * - most recently used element is put at the head, whereas least recently used element is
 *   put at the tail
 *   when get or set an element, update the head and the tail if necessay
 * - use a hash mapping from keys to pointers to quickly access the elements of the list
 *   when the size of the list/map exceeds the capacity, delete and update the tail
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    Node *next, *prev;
    int key, value;
    Node(int k, int v) : key(k), value(v), next(NULL), prev(NULL) { }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        unordered_map<int, Node*>::iterator itr = mp.find(key);
        if (itr == mp.end()) return -1;
        else {
            Node *found = itr -> second;
            if (head != found) {
                if (found == tail) tail = tail -> prev;
                if (found -> prev != NULL) (found -> prev) -> next = found -> next;
                if (found -> next != NULL) (found -> next) -> prev = found -> prev;
                head -> prev = found;
                found -> next = head, found -> prev = NULL;
                head = found;
            }
            return found -> value;
        }
    }
    
    void set(int key, int value) {
        unordered_map<int, Node*>::iterator itr = mp.find(key);
        if (itr == mp.end()) {
            if (mp.size() == 0) {
                head = tail = new Node(key, value);
            } else {
                Node *tmp = head;
                head = new Node(key, value);
                head -> next = tmp;
                tmp -> prev = head;
            }
            mp[key] = head;
            if (mp.size() > maxSize) {
                Node *tmp = tail;
                tail = tail -> prev; 
                tail -> next = NULL;
                mp.erase(tmp -> key);
                delete tmp;
            } 
        } else {
            (itr -> second) -> value = value;
            get(key);
        }
    }

private:
    Node *head, *tail;
    unordered_map<int, Node*> mp;
    int maxSize;
};

int main() {
    LRUCache cache(2);
    cache.set(2, 1);
    cache.set(1, 1);
    cache.set(2, 3);
    cache.set(4, 1);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    return 0;
}
