/* - traverse the input singly-linked list and establish mapping from pointer to index
 *   ex. index     0         1         2         3
 *       pointer   pointer0  pointer1  pointer2  pointer3
 * - create the duplicate singly-linked list and establish reverse mapping from index to pointer
 * - traverse the input singly-linked list once again and create the random pointers of the new
 *   list
 * - the time can be improved by first interleavingly inserting the nodes of the duplicate list 
 *   into the input linked list. next, create the random pointers of the duplicate list, and
 *   finally separate the two lists
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class RandomListNode {
public:
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) { }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, int> mp;
        unordered_map<int, RandomListNode*> remp;
        RandomListNode *chead = NULL, *citr = NULL, *prev = NULL;
        int i = 0;
        for (RandomListNode *itr = head; itr != NULL; itr = itr -> next) {
            citr = new RandomListNode(itr -> label);
            if (chead == NULL) chead = citr;
            if (prev != NULL) prev -> next = citr;
            mp[itr] = i;
	    remp[i] = citr;
	    prev = citr;
            i++;
        }
        mp[NULL] = i;
        citr = chead;
        for (RandomListNode *itr = head; itr != NULL; itr = itr -> next) {
            citr -> random = remp[mp[itr -> random]];
            citr = citr -> next;
        }
        return chead;
    }
};

int main() {
    return 0;
}
