/* - priority_queue<int> q;                             ==> maximum priority queue (default)
 *   priority_queue<int, vector<int>, greater<int> > q; ==> minimum priority queue
 *     greater<int>: i.e. >, if x > y (x precedes y), y gets onto the top of x
 * - priority queue with a self-defined comparison function:
 *   class Comparison {
 *       bool operator()(int &x, int &y) {
 *           return x > y;
 *       }
 *   };
 *   priority_queue<int, vector<int>, Comparison> q;    ==> minimum priority queue
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Comparison {
public:
    bool operator()(ListNode* &l, ListNode* &r) {
        return l -> val > r -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparison> q;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != NULL) q.push(lists[i]);
        if (q.empty()) return NULL;
        ListNode *head = q.top(), *itr = NULL, *prev = NULL;
        while (!q.empty()) {
            itr = q.top();
            q.pop();
            if (prev != NULL) prev -> next = itr;
            if (itr -> next != NULL) q.push(itr -> next);
            prev = itr;
        }
        return head;
    }
};

int main() {
    return 0;
}
