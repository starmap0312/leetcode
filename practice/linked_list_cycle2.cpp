/* - the algorithm uses O(1) space: by advancing two pointers at the same time, one takes a step
 *   and the other takes two steps in the linked list at each iteration
 *   if there exists a cycle in the linked list, then two pointers will arrive at the same node
 *   at some point of time
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
            if (itrOne == itrTwo) return true;
            itrOne = itrOne -> next;
            if (itrTwo -> next == NULL) break;
            itrTwo = itrTwo -> next -> next;
        }
        return false;
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
