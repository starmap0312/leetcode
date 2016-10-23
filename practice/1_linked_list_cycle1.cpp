/* - a linked list contains a cycle <=> visits a node more than once if following the list
 * - use a set to keep track of the visited nodes: O(n) space
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
        while (itr != NULL) {                         // traverse the list from the head
            if (visited.find(itr) != visited.end()) { // if the node is visited, return true (i.e. has cycle)
                return true; 
            }
            visited.insert(itr);
            itr = itr -> next;
        }
        return false;                                 // return false (i.e. no cycle)
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
