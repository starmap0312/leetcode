/* - ListNode *head = new ListNode(3); ==> to delete a ListNode, use delete head;
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
    ListNode * deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *prev = head, *cur = head -> next;
        while (cur != NULL) {
            if (cur -> val == prev -> val) {
                delete prev -> next;
                prev -> next = cur -> next;
            } else {
                prev = cur;
            }
            cur = cur -> next;
        }
        return head;
    }
};

int main() {
    int a[5] = { 1, 1, 2, 3, 3 };
    ListNode *head, *itr;
    head = itr = new ListNode(a[0]);
    for (int i = 1; i < 5; i++) {
        itr -> next = new ListNode(a[i]);
        itr = itr -> next;
    }
    Solution solution;
    solution.deleteDuplicates(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
