/* - simulate in-order traversal using a stack
 *   nodes in the stack represent nodes whose left child already visited by DFS, so next()
 *   function outputs the top node value and continues the traversal of the right child, and
 *   traverse the leftmost path of the right child, pushing the nodes to the stack, since the 
 *   nodes whose left child already visited
 */
#include <iostream>
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
        pushLeftmost(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * itr = s.top();
        int value = itr -> val;
        TreeNode * rightNode = itr -> right;
        s.pop();
        pushLeftmost(rightNode);
        return value;
    }
    void pushLeftmost(TreeNode *itr) {
        if (itr == NULL) return;
        else s.push(itr);
        while (itr -> left != NULL) {
            s.push(itr -> left);
            itr = itr -> left;
        }
    }
private:
    stack<TreeNode*> s;
};

int main() {
    TreeNode *root = new TreeNode(4);
    root -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(2);
    root -> left -> right -> right = new TreeNode(3);
    BSTIterator tree = BSTIterator(root);
    while (tree.hasNext())
        cout << tree.next() << " ";
    cout << endl;
    return 0;
}
