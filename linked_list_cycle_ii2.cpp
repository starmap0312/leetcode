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
    ListNode* detectCycle(ListNode *head) {
        ListNode *cycleNode = findCycleNode(head);
        if (cycleNode == NULL) return NULL;
        else {
            ListNode *itr = head;
            while (!inCycle(itr, cycleNode)) {
                itr = itr -> next;
            }
            return itr;
        }
    }
    ListNode* findCycleNode(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;
        ListNode *slow = head, *fast = head -> next;
        while (fast != slow) {
            if (fast -> next == NULL || fast -> next -> next == NULL)
                return NULL;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return fast;
    }
    bool inCycle(ListNode *node, ListNode *cycleNode) {
        if (node == cycleNode) return true;
        for (ListNode *itr = cycleNode -> next; itr != cycleNode; itr = itr -> next) {
            if (node == itr) return true;
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
    ListNode * node = solution.detectCycle(head);
    cout << (node == NULL? 0: node -> val) << endl;
    return 0;
}
