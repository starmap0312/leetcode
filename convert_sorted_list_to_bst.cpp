#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        int index = findLength(head) / 2;
        ListNode* prev;
        ListNode* middle = getNode(head, index, prev);
        if (middle != NULL) {
            TreeNode* root = new TreeNode(middle -> val);
            root -> right = sortedListToBST(middle -> next);
            if (prev != middle) {
                prev -> next = NULL;
                root -> left = sortedListToBST(head);
            } else root -> left = NULL;
            return root;
        } else return NULL;
    }
    ListNode* getNode(ListNode* head, int index, ListNode* &prev) {
        if (head == NULL) { prev = NULL; return NULL; }
        ListNode* result = head;
        prev = head;
        for (int i = 0; i < index; i++) {
            prev = result;
            result = result -> next;
        }
        return result;
    }
    int findLength(ListNode *head) {
        if (head == NULL) return 0;
        else return findLength(head -> next) + 1;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(3);
    Solution solution;
    solution.sortedListToBST(head);
    return 0;
}
