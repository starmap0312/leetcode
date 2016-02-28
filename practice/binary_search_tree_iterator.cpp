/* - the problem can solved using an approach similar to binary tree in-order traversal
 *   i.e. 1) push all the nodes of the leftmost path from the root to the stack
 *        2) pop the top element and return its value as the next element
 *           after the pop, if the top element has a right child, push all the nodes of the
 *           leftmost path from the right child to the stack
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *itr = root;
        while (itr != NULL) {
            q.push(itr);
            itr = itr -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (q.empty()) return -1;
        TreeNode *node = q.top();
        int value = node -> val;
        q.pop();
        if (node -> right != NULL) {
            TreeNode *itr = node -> right;
            while (itr != NULL) {
                q.push(itr);
                itr = itr -> left;
            }
        }
        return value;
    }

private:
    stack<TreeNode*> q;
};

int main() {
    TreeNode *root = new TreeNode(3);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(7);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(9);
    BSTIterator iterator(root);
    while (iterator.hasNext()) {
        cout << iterator.next() << endl;
    }
    return 0;
}
