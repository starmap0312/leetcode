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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = findLength(head) - n - 1;
        ListNode *itr = head;
        for (int i = 0; i < index; i++)
            itr = itr -> next;
        if (index == -1 && head != NULL)
            head = head -> next;
        else if (itr -> next != NULL)
            itr -> next = itr -> next -> next;
        return head;
    }
    int findLength(ListNode* head) {
        int i = 0;
        while (head != NULL) {
            i++;
            head = head -> next;
        }
        return i;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next= new ListNode(5);
    Solution solution;
    solution.removeNthFromEnd(head, 2);
    for (ListNode *itr = head; itr != NULL; itr = itr -> next)
        cout << itr -> val << " ";
    cout << endl;
    return 0;
}
