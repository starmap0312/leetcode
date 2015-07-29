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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = findLength(headA), lengthB = findLength(headB);
        if (lengthA < lengthB) headB = findNode(headB, lengthB - lengthA);
        if (lengthA > lengthB) headA = findNode(headA, lengthA - lengthB);
        return findIdentical(headA, headB);
    }
    ListNode *findIdentical(ListNode *headA, ListNode *headB) {
        ListNode *itrA, *itrB;
        for (itrA = headA, itrB = headB; itrA != NULL && itrA != itrB; 
            itrA = itrA -> next, itrB = itrB -> next) { }
        return itrA;
    }
    ListNode *findNode(ListNode *head, int length) {
        ListNode *itr = head;
        for (itr = head; itr != NULL && length > 0; itr = itr -> next, length--) { }
        return itr;
    }
    int findLength(ListNode *head) {
        int length = 0;
        for (ListNode *itr = head; itr != NULL; itr = itr -> next)
            length++;
        return length;
    }
};

int main() {
    return 0;
}
