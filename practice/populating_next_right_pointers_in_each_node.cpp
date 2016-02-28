/*
 *          1         ...... level 0
 *      2 ----> 3     ...... level 1
 *    4   5   6   7   ...... level 2
 * - suppose we are at level 1 of the tree, i.e. node 2 and node 3
 *   start from node 2:
 *     1. set up the next pointers of its left and right child (i.e. node 4 and node 5)
 *     2. follow the next pointer of node 2 proceeds to node 3
 *     3. set up the next pointers of its left and right child (i.e. node 6 and node 7)
 *   proceeds to the next level, i.e. level 2
 *   as there are no level 3, the procedure terminates
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
        TreeLinkNode *start = root;
        // the loop is executed only if there are nodes at next level of the tree
        while (start -> left != NULL) {
            TreeLinkNode *itr = start; // the beginning node at next level of the tree
            // set up the next pointers of the nodes at the next level
            while (itr != NULL) {
                itr -> left -> next = itr -> right; // set up the next pointer of the left child
                if (itr -> next != NULL) // set up the next pointer of the right child
                    itr -> right -> next = itr -> next -> left;
                itr = itr -> next;
            }
            start = start -> left; // update itr to the begining node at the next level
        }
    }
};

int main() {
    return 0;
}
