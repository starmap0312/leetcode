/* - create a dummy head node to simplify the code
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if (l1 != NULL) cur -> next = l1;
        else if (l2 != NULL) cur -> next = l2;
        return dummy -> next;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1 -> next = new ListNode(3);
    l1 -> next -> next = new ListNode(7);
    ListNode *l2 = new ListNode(2);
    l2 -> next = new ListNode(4);
    l2 -> next -> next = new ListNode(5);
    Solution solution;
    ListNode *head = solution.mergeTwoLists(l1, l2);
    for (ListNode* itr = head; itr != NULL; itr = itr -> next) {
        cout << itr -> val << " ";
    }
    cout << endl;
    return 0;
}
