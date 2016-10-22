/* - traverse the tree in a depth-first order
 *     during the traversal, use a stack to remember the nodes whose right subtrees 
 *     not yet been visited
 * - intially, the stack contains only one dummy node whose right child is the root
 * - while the stack is not empty:
 *       pop out the top element, say node i
 *       traverse and push to all the nodes in the leftmost path of the right child of node i to the stack
 * - 1) preorder traversal:
 *      output the nodes before pushing the nodes to the stack
 *   2) inorder traversal:
 *      output node i when pop it out of the stack
 *   3) postorder traversal:
 *      when node i is to be poped out of the stack for the first time
 *      do not actually pop it out, as we need to output it after the traversal of 
 *      its right subtree is complete
 *      so we can define an additional field in the node structure to acomplish this
 *      alternatively, we can push each node to the stack twice to distinguish
 *      if the node is the first time poped out or its right subtree is traversed
 *      or we can use an additional pointer, say lastVisisted, to remember what is
 *      the last visited node (a more succint and dedicate way)
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
            while (itr != NULL) {             // push all the nodes in the leftmost path of the right child of itr to stack
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
            result.push_back(itr -> val); // output the node when it is about to be poped out of the stack
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {
                q.push(itr);
                itr = itr -> left;
            }
        }
        result.erase(result.begin());     // remove value of the first dummpy node
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
                while (itr != NULL) {
                    q.push(itr);
                    itr = itr -> left;
                }
            } else {
                result.push_back(itr -> val);
                q.pop();                 // pop out the element only when the node is visited (its left subtree is done with traversal)
            }
        }
        result.erase(result.end() - 1);   // remove value of the first dummpy node
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
