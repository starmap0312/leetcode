/* - an O(1) space solution
 *   advance two pointers at the same time, one takes a step and the other takes two steps 
 *   if there exists a cycle, then the two pointers will arrive at the same node
 *   otherwise, the second pointer will first reach the end of the linked list
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *itrOne = head, *itrTwo = head -> next;
        while (itrTwo != NULL) {
            if (itrOne == itrTwo) {            // if two pointers meet at some point, return true (i.e. has cycle)
                return true;
            }
            itrOne = itrOne -> next;           // advance itrOne by one step
            if (itrTwo -> next == NULL) break; // advance itrTwo by two steps
            itrTwo = itrTwo -> next -> next;
        }
        return false;                          // return false (i.e. no cycle)
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = head -> next;
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    return 0;
}
