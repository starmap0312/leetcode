/* - use slow and fast pointers to avoid using extra space (simplified code)
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
        if (head == NULL || head -> next == NULL) return false;
        ListNode *slow = head, *fast = head -> next;
        while (fast != slow) {
            if (fast -> next == NULL || fast -> next -> next == NULL)
                return false;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return true;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    return 0;
}
