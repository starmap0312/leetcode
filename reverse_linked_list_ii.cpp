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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *first = NULL, *second = NULL, *prev = NULL, *cur = head;
        for (int i = 0; i < n; i++) {
            ListNode *tmp = cur -> next;
            if (i < m - 2) { }
            else if (i == m - 2) first = cur;
            else {
                if (i == m - 1) second = cur;
                cur -> next = prev;
            }
            prev = cur;
            cur = tmp;
        }
        second -> next = cur;
        if (first != NULL) first -> next = prev;
        else head = prev;
        return head;
    }

};

int main() {
    ListNode *head, *itr;
    head = itr = new ListNode(1);
    for (int i = 2; i <= 5; i++) {
        itr -> next =  new ListNode(i);
        itr = itr -> next;
    }
    Solution solution;
    head = solution.reverseBetween(head, 2, 4);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
