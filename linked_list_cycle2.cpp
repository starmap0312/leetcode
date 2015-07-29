/* - use slow and fast pointers to avoid using extra space
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
        if (head == NULL) return false;
        ListNode *slow = head, *fast = head -> next;
        while (fast != NULL) {
            fast = fast -> next;
            if (fast == slow) return true;
            if (fast == NULL) return false;
            fast = fast -> next;
            if (fast == slow) return true;
            if (fast == NULL) return false;
            slow = slow -> next;
        }
        return false;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = head;
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    return 0;
}
