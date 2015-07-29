/* - traverse the list by while-loop, maintain a set of visisted node pointers, and
 *   check if the next node is already visted during traversal
 */
#include <iostream>
#include <set>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        while (head != NULL) {
            if (s.find(head) != s.end()) break;
            s.insert(head);
            head = head -> next;
        }
        return (head != NULL? head: NULL);
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = head;
    Solution solution;
    ListNode *node = solution.detectCycle(head);
    cout << (node == NULL? 0: node -> val) << endl;
    return 0;
}
