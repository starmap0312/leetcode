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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *itr;
        head = itr = new ListNode(0);
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum;
            if (l1 != NULL && l2 != NULL) {
                sum = l1 -> val + l2 -> val + carry;
                l1 = l1 -> next, l2 = l2 -> next;
            } else if (l1 != NULL && l2 == NULL) {
                sum = l1 -> val + carry;
                l1 = l1 -> next;
            } else if (l1 == NULL && l2 != NULL) {
                sum = l2 -> val + carry;
                l2 = l2 -> next;
            }
            itr -> next = new ListNode(sum % 10);
            if (sum / 10 == 1) carry = 1;
            else carry = 0;
            itr = itr -> next;
        }
        if (carry == 1) itr -> next = new ListNode(1);
        return head -> next;
    }
};

int main() {
    ListNode *l1 = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);
    Solution solution;
    ListNode *sum = solution.addTwoNumbers(l1, l2);
    for (ListNode *itr = sum; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
