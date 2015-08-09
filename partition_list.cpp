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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode *first = NULL, *second = NULL, *firstHead = NULL, *secondHead = NULL;
        for (ListNode *itr = head; itr != NULL; itr = itr -> next) {
            if (itr -> val < x) {
                if (first == NULL) firstHead = first = itr;
                else {
                    first -> next = itr;
                    first = first -> next;
                }
            } else {
                if (second == NULL) secondHead = second = itr;
                else {
                    second -> next = itr;
                    second = second -> next;
                }
            }
        }
        if (first != NULL) first -> next = secondHead;
        if (second != NULL) second -> next = NULL;
        if (firstHead != NULL) return firstHead;
        else return secondHead;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(4);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(2);
    head -> next -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next -> next = new ListNode(2);
    Solution solution;
    ListNode *rc = solution.partition(head, 3);
    for (ListNode *itr = rc; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;    
    return 0;
}
