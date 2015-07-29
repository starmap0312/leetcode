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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *itr = head -> next;
        head -> next = NULL;
        while (itr != NULL) {
            ListNode *tmp = itr -> next;
            head = insert(itr, head);
            itr = tmp;
        }
        return head;
    }
    ListNode* insert(ListNode *itr, ListNode *head) {
        ListNode *prev = NULL, *cur = head;
        while (cur != NULL && cur -> val < itr -> val) {
            prev = cur;
            cur = cur -> next;
        }
        if (prev == NULL) {
            itr -> next = head;
            head = itr;
        } else {
            itr -> next = prev -> next;
            prev -> next = itr;
        }
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head -> next = new ListNode(1);
    head -> next -> next = new ListNode(5);
    Solution solution;
    head = solution.insertionSortList(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
