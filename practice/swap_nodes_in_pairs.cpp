/* - the problem can be solved iteratively using two pointers prev and cur:
 *   ex.
 *     1) update the first two nodes' next pointers
 *        prev        cur
 *        1     2     3      4      5      6
 *        ^     |            ^
 *        |-----|            |
 *                           |
 *        |                  |
 *        |------------------|
 *
 *     2) proceed pointers prev and cur, and then update the next two nodes' next pointers
 *                    prev          cur
 *        1     2     3      4      5      6
 *                    ^      |             ^
 *                    |------|             |
 *                                         |
 *                    |                    |
 *                    |--------------------|
 *     3) need to handle the last iteration where cur == NULL or cur -> next == NULL
 */
#include <iostream>
#include <vector>

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
        ListNode *prev = head, *cur = head -> next -> next;
        head = head -> next;
        while (prev -> next != NULL) {
            prev -> next -> next = prev;
            if (cur == NULL || cur -> next == NULL) {
                // handle the update of pointers the last iteration
                prev -> next = cur;
                break;
            }
            prev -> next = cur -> next;
            prev = cur; // proceed pointer prev
            cur = cur -> next; // proceed pointer cur
            if (cur != NULL) cur = cur -> next;
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head = solution.swapPairs(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
