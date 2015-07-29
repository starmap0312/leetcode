/* - get familar with list implementation
 *   class Node {
 *   public:
 *       int val;
 *       Node *next;
 *       Node(int x) : val(x), next(NULL) { }
 *   };
 *   // client of list
 *   Node *head = new Node(1), head -> next = new Node(2), head -> next -> next = new Node(3);
 *   // to traverse list
 *   for (Node *itr = head; itr != NULL; itr = itr -> next) {
 *       cout << itr -> val << endl;
 *   }
 */
#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode *second = head -> next;
        head -> next = swapPairs(second -> next);
        second -> next = head;
        return second;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    Solution solution;
    head = solution.swapPairs(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
