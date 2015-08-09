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
    ListNode* sortList(ListNode* head) {
        int length = findLength(head);
        if (length < 2) return head;
        ListNode* tail = findNode(head, length / 2);
        ListNode* second = tail -> next;
        tail -> next = NULL;
        head = sortList(head), second = sortList(second);
        head = merge(head, second);
        return head;
    }
    ListNode *merge(ListNode* first, ListNode* second) {
        ListNode *head, *itr;
        if (first -> val < second -> val) {
            head = itr = first;
            first = first -> next;
        } else {
            head = itr = second;
            second = second -> next;
        }
        while (first != NULL && second != NULL) {
            if (first -> val < second -> val) {
                itr -> next = first;
                first = first -> next;
            } else {
                itr -> next = second;
                second = second -> next;
            }
            itr = itr -> next;
        }
        if (first != NULL) itr -> next = first;
        if (second != NULL) itr -> next = second;
        return head;
    }
    ListNode *findNode(ListNode* head, int length) {
        while (length > 1 && head != NULL) {
            head = head -> next;
            length--;
        }
        return head;
    }
    int findLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            head = head -> next;
            length++;
        }
        return length;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head -> next = new ListNode(1);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next = new ListNode(4);
    Solution solution;
    head = solution.sortList(head);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
