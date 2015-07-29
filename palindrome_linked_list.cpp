/* - naive approachs require O(n^2) time or O(n) space
 *   to achieve O(n) time and O(1), we first identify the right half of the list, and perform
 *   reversing the list in O(n) time and O(1) space by traversing the list and modifying the
 *   next pointers of each node one by one. finally, perform a simple comparison between the 
 *   left half of the list and the reversed right half of the list.
 */
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) return true;
        int length = findLength(head);
        ListNode *middle = findMiddleNode(head, length);
        middle = reverseList(middle);
        return compare(head, middle);
    }
    bool compare(ListNode *first, ListNode *second) {
        while (first != NULL && second != NULL) {
            if (first -> val != second -> val)
                return false;
            first = first -> next;
            second = second -> next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) return head;
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
    int findLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head -> next;
        }
        return length;
    }
    ListNode *findMiddleNode(ListNode *head, int length) {
        int pos = length / 2;
        while (head != NULL && pos > 0) {
            head = head -> next;
            pos--;
        }
        if (length % 2 == 1)
            head = head -> next;
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(1);
    Solution solution;
    cout << solution.isPalindrome(head) << endl;
    return 0;
}
