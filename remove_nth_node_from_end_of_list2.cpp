/* - do it in one pass by maintaining two pointers of distance n
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *last =  head;
        for (int i = 0; i < n; i++) {
            last = last -> next;
        }
        if (last == NULL) return head -> next;
        while (last -> next != NULL) {
            first = first -> next;
            last = last -> next;
        }
        first -> next = first -> next -> next;
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next= new ListNode(5);
    Solution solution;
    solution.removeNthFromEnd(head, 2);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
