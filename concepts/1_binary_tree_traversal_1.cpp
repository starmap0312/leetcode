/* - traverse the tree in a depth-first order
 *     during the traversal, use a stack to remember the nodes whose right subtrees not yet been visited
 * - intially, the stack contains only one dummy node whose right child is the root
 * - while the stack is not empty:
 *       pop out the top element, say node i
 *       traverse and push to all the nodes in the leftmost path of the right child of node i to the stack
 * - 1) preorder traversal:
 *      output the node before pushing to the stack
 *   2) inorder traversal:
 *      output the node before popping out of the stack
 *   3) postorder traversal:
 *      node is not poped out of the stack when first visited (use an additional field for node visited) 
 *      node is popped out when already visited, i.e. it is done with traversal of its left subtree
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    bool visited;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), visited(false) { }
};

class Solution {
private:
    void initializeStack(stack<TreeNode *> &q, TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        dummy -> right = root;
        q.push(dummy);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        initializeStack(q, root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {             // push nodes of the leftmost path to the stack
                result.push_back(itr -> val); // output the node before pushing to stack
                q.push(itr);
                itr = itr -> left;
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        initializeStack(q, root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            result.push_back(itr -> val);     // output the node before popping out of the stack
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {             // push nodes of the leftmost path to the stack
                q.push(itr);
                itr = itr -> left;
            }
        }
        result.erase(result.begin());         // remove value of dummpy node (the first popped out node)
        return result; 
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        initializeStack(q, root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            if (!itr -> visited) {
                itr -> visited = true;
                itr = itr -> right;
                while (itr != NULL) {         // push nodes of the leftmost path to the stack
                    q.push(itr);
                    itr = itr -> left;
                }
            } else {
                result.push_back(itr -> val); // output the node before popping out of the stack
                q.pop();                      // node is popped out only when it has been visited
                                              // i.e. its left subtree is done with traversal
            }
        }
        result.erase(result.end() - 1);       // remove value of dummpy node (the last popped out node)
        return result; 
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    root -> right -> right = new TreeNode(4);
    root -> right -> left -> left = new TreeNode(5);
    root -> right -> left -> right = new TreeNode(6);
    //    1
    //      2
    //    3   4
    //  5   6
    Solution solution;
    cout << "solution.preorderTraversal:  ";
    vector<int> rc = solution.preorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    cout << "solution.inorderTraversal:   ";
    rc = solution.inorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    cout << "solution.postorderTraversal: ";
    rc = solution.postorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
