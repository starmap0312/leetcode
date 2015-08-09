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
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL) return;
        ListNode *first, *second;
        splitList(head, first, second);
        second = reverseList(second);
        mergeList(first, second);
    }
    void mergeList(ListNode* first, ListNode* second) {
        while (first != NULL && second != NULL) {
            //cout << first -> val << "," << second -> val << endl;
            ListNode *nextFirst = first -> next;
            ListNode *nextSecond = second -> next;
            first -> next = second;
            second -> next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode *prev = head, *cur = head -> next;
        prev -> next = NULL;
        while (cur != NULL) {
            ListNode *tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    ListNode* findMiddle(ListNode* head) {
        int length = 0;
        ListNode* itr = head;
        while (itr != NULL) {
            length++;
            itr = itr -> next;
        }
        length = length / 2;
        while (length > 0 && head != NULL) {
            length--;
            head = head -> next;
        }
        return head;
    }
    void splitList(ListNode* head, ListNode* &first, ListNode* &second) {
        first = head;
        ListNode* middle = findMiddle(head);
        second = middle -> next;
        middle -> next = NULL;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    Solution solution;
    solution.reorderList(head);
    return 0;
}
