/* - manipulation of the linked list by two ListNode pointers
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
    ListNode* reverseList(ListNode* head) {
       if (head == NULL) return head;
       ListNode *prev = NULL, *cur = head;
       while (cur != NULL) {
           ListNode *tmp = cur -> next;
           cur -> next = prev;
           prev = cur;
           cur = tmp;
       } 
       return prev;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2), head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    Solution solution;
    head = solution.reverseList(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
