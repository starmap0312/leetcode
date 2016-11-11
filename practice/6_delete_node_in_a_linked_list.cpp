/* - because the list is NOT doubly-linked list, we cannot easily get the previous node of the node to be deleted
 *
 * ex.         x             ==> delete node
 *   1 -> 2 -> 3 -> 4 -> 5
 *
 *   1 -> 2 -> 4 -> 5
 *
 *   the solution is to copy next node's value to the node to be deleted, and then delete the next node instead
 *   i.e.
 *                   x       ==> delete node
 *   1 -> 2 ->(4) -> 4 -> 5
 *
 *   1 -> 2 ->(4) -> 5
 */
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(Node* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};

int main() {
    Node *head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);
    Solution solution;
    solution.deleteNode(head -> next -> next);
    for (Node *itr = head; itr != NULL; itr = itr -> next) {
        cout << itr -> val << " ";
    }
    cout << endl;
    return 0;
}
