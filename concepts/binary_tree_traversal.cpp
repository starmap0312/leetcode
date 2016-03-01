/* - traverse the tree in a depth-first order
 *   during the traversal, use a stack to remember the nodes whose right subtrees 
 *   yet been visited
 * - intially, the stack contains only one dummy node whose right child is the root
 * - while the stack is not empty:
 *       pop out the top element, say node i
 *       traverse the nodes in the leftmost path from node i
 *       push every node in the leftmost path into stack during the traversal
 * - 1) preorder traversal:
 *       output the nodes visited while pushing the nodes in the leftmost path into
 *       the stack
 *   2) inorder traversal:
 *       output node i when pop it out of the stack
 *   3) postorder traversal:
 *       when node i is to be poped out of the stack at the first time
 *       do not actually pop it out, as we need to output it after the traversal of 
 *       its right subtree is complete
 *       so we can define an additional field in the node structure to acomplish this
 *       alternatively, we can push each node to the stack twice to distinguish
 *       if the node is the first time poped out or its right subtree is traversed
 *       or we can use an additional pointer, say lastVisisted, to remember what is
 *       the last visited node (a more succint and dedicate way)
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

class Solution {
private:
    TreeNode* initializeStack(stack<TreeNode *> &q, TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        dummy -> right = root;
        q.push(dummy);
        return dummy;
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        TreeNode *dummy = initializeStack(q, root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {
                q.push(itr);
                result.push_back(itr -> val);
                itr = itr -> left;
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        TreeNode *dummy = initializeStack(q, root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            result.push_back(itr -> val);
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {
                q.push(itr);
                itr = itr -> left;
            }
        }
        return vector<int> (result.begin() + 1);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        TreeNode *dummy = initializeStack(q, root);
        q.push(dummy);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            q.pop();
            if (q.empty() || q.top() != itr) {
                result.push_back(itr -> val);
                continue;
            }
            itr = itr -> right;
            while (itr != NULL) {
                q.push(itr), q.push(itr);
                itr = itr -> left;
            }
        }
        return vector<int> (result.begin() + 1);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    Solution solution;
    vector<int> rc = solution.preorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    rc = solution.inorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    rc = solution.postorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
