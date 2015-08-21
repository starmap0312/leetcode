/* - an improved algorithm that uses O(1) extra space
 * - the algorithm proceeds from top to bottom, level by level: once the next pointers of level i
 *   are all set, the next pointers of level i + 1 can be set by traversing nodes of level i
 *   from left to right
 */
#include <iostream>

using namespace std;

class TreeLinkNode {
public:
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) { }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *itr = root, *next = root -> left;
        while (itr != NULL && next != NULL) {
            TreeLinkNode *prev = NULL;
            while (itr != NULL) {
               if (prev != NULL) {
                   prev -> left -> next = prev -> right;
                   prev -> right -> next = itr -> left;
               }
               prev = itr;
               itr = itr -> next; 
            }
            if (prev != NULL && prev -> left != NULL)
                prev -> left -> next = prev -> right;
            itr = next;
            next = itr -> left;
        }
    }
};

int main() {
    return 0;
}
