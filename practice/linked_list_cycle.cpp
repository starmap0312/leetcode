/* - a linked list contains a cycle if and only if one follows the linked list and visits a node
 *   more than once
 * - the algorithm uses a set to keep track of the nodes visited, which takes O(n) space
 */
#include <iostream>
#include <set>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> visited;
        ListNode *itr = head;
        while (itr != NULL) {
            if (visited.find(itr) != visited.end()) return true; 
            visited.insert(itr);
            itr = itr -> next;
        }
        return false;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = head -> next;
    Solution solution;
    cout << solution.hasCycle(head) << endl;
    return 0;
}
