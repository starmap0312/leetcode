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
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while (head != NULL) {
            if (s.find(head) != s.end()) break;
            s.insert(head);
            head = head -> next;
        }
        return (head != NULL);
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    return 0;
}
