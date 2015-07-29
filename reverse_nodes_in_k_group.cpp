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
    bool isNotFull(ListNode* cur, int k) {
        for(int i = 0; i < k - 1; i++) {
            if (cur -> next != NULL) cur = cur -> next;
            else return true;
        }
        return false;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1 || isNotFull(head, k)) return head;
        ListNode* front = head;
        for(int i = 0; i < k - 1; i++) {
            ListNode* end = head -> next;
            head -> next = end -> next;
            end -> next = front;
            front = end;
        }
        head -> next = reverseKGroup(head -> next, k);
        return front;
    }
};

int main() {

    return 0;
}
