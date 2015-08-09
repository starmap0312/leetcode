/* - use dummpy head nodes to simplify the code
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *firstDummy = new ListNode(0), *secondDummy = new ListNode(0);
        ListNode *firstItr = firstDummy, *secondItr = secondDummy;
        for (ListNode *itr = head; itr != NULL; itr = itr -> next) {
            if (itr -> val < x) {
               firstItr -> next = itr;
               firstItr = firstItr -> next;
            } else {
               secondItr -> next = itr;
               secondItr = secondItr -> next;
            }
        }
        firstItr -> next = secondDummy -> next;
        secondItr -> next = NULL;
        return firstDummy -> next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(4);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(2);
    head -> next -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next -> next = new ListNode(2);
    Solution solution;
    ListNode *rc = solution.partition(head, 3);
    for (ListNode *itr = rc; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;    
    return 0;
}
