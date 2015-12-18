/* - the problem can be solved by observing that the next pointers of level i can be constructed
 *   using the next pointers of level i - 1
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
        TreeLinkNode *parent = root;
        while (parent != NULL) {
            TreeLinkNode *itr = NULL, *next = NULL;
            while (parent != NULL) {
                if (parent -> left != NULL) {
                    if (itr == NULL) next = parent -> left;
                    else itr -> next = parent -> left;
                    itr = parent -> left;
                }
                if (parent -> right != NULL) {
                    if (itr == NULL) next = parent -> right;
                    else itr -> next = parent -> right;
                    itr = parent -> right;
                }
                parent = parent -> next;
            }
            parent = next;
        }
    }
};

int main() {
    return 0;
}
