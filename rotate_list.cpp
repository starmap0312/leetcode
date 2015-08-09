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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k <= 0 || head == NULL) return head;
        ListNode *tail = NULL;
        int length = findLength(head, tail);
        int offset = length - (k % length);
        if (offset <= 0) return head;
        ListNode *itr = head;
        while (offset > 1) {
            itr = itr -> next;
            offset--;
        }
        tail -> next = head;
        head = itr -> next;
        itr -> next = NULL;
        return head;
    }
    int findLength(ListNode* head, ListNode* &tail) {
        int length = 0;
        while (head != NULL) {
            tail = head;
            head = head -> next;
            length++;
        }
        return length;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    Solution solution;
    head = solution.rotateRight(head, 2);
    for (ListNode* itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
