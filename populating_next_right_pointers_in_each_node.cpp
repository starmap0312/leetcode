/* - use recursion, the recursion takes extra space in the stack
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
        TreeLinkNode *itr1 = root -> left, *itr2 = root -> right;
        while (itr1 != NULL && itr2 != NULL) {
            itr1 -> next = itr2;
            itr1 = itr1 -> right;
            itr2 = itr2 -> left;
        }
        connect(root -> left);
        connect(root -> right);
    }
};

int main() {
    return 0;
}
