/* 
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
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *prev = NULL, *cur = head;
        while (cur != NULL) {
            ListNode *end = findSameEnd(cur);
            ListNode *tmp = end -> next;
            if (cur == end) { // cur points to a unique node
                if (prev == NULL) head = end;
                prev = end;
            } else { // cur points to a list of identical nodes ending at node pointed by end
                if (prev != NULL) prev -> next = end -> next;
            }
            cur = end -> next; 
        }
        return (prev == NULL? NULL: head);
    }
    ListNode* findSameEnd(ListNode *cur) {
        while (cur -> next != NULL) {
            if (cur -> val == cur -> next -> val) cur = cur -> next;
            else break;
        }
        return cur;
    }
};

int main() {
    int a[7] = { 1, 2, 3, 3, 4, 4, 5 };
    ListNode *head, *itr;
    head = itr = new ListNode(a[0]);
    for (int i = 1; i < 7; i++) {
        itr -> next = new ListNode(a[i]);
        itr = itr -> next;
    }
    Solution solution;
    head = solution.deleteDuplicates(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
