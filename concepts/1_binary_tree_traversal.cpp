/* 
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.top();
            q.pop();
            result.push_back(node -> val);
            if (node -> right != NULL) {
                q.push(node -> right);
            }
            if (node -> left != NULL) {
                q.push(node -> left);
            }
        }
        return result;
    }

    // we revert the visiting order of preorder traversal and also revert the output order using another stack
    // ex.
    //     1
    //   2   3
    //
    //   pre-order:  1, 2, 3 (1 -> 2 -> 3, the output is the same as the visiting order)
    //   post-order: 2, 3, 1 (1 -> 3 -> 2, revert the visiting order and also the output order)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        stack<int> output;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.top();
            q.pop();
            output.push(node -> val);
            if (node -> left != NULL) {
                q.push(node -> left);
            }
            if (node -> right != NULL) {
                q.push(node -> right);
            }
        }
        while (!output.empty()) { // pop elements from the stack 
            result.push_back(output.top());
            output.pop();
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        TreeNode *cur = root;
        while (true) {
            while (cur != NULL) { // push all the nodes in the leftmost path to the stack
                q.push(cur);
                cur = cur -> left;
            }
            if (q.empty()) break; // break the loop only if there is no more node to visit in the stack
            // pop one node from the stack, which means that the left subtree of that node is done with traversal
            TreeNode *node = q.top();
            q.pop();
            result.push_back(node -> val);
            cur = node -> right;
        }
        return result;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        TreeNode *cur = root;
        bool done = false; // similar to inorderTraversal, but use a flag for loop control
        while (!done) {
            if (cur != NULL) { // continue to push all the nodes in the leftmost path to the stack
                q.push(cur);
                cur = cur -> left;
            } else {
                if (q.empty()) {
                    done = true; // break the loop only if there is no more node to visit in the stack
                } else {
                    // pop one node from the stack, which means that the left subtree of that node is done with traversal
                    TreeNode *node = q.top();
                    q.pop();
                    result.push_back(node -> val);
                    cur = node -> right;
                }
            }
        }
        return result;
    }

    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        q.push(root);
        while (!q.empty()) { // each node contains an additional field (visited), a node is popped out only if its left subtree is traversed
            TreeNode *cur = q.top();
            if (cur != NULL) {
                if (!cur -> visited) { // first time visit the node
                    q.push(cur -> left);
                } else {               // the node is already visited, meaning that its left subtree is done with traversal
                    result.push_back(cur -> val);
                    q.pop();
                    q.push(cur -> right);
                }
            } else {
                q.pop();               // pop out the NULL pointer
                if (!q.empty()) {      // the next node in the stack is marked as visited
                    q.top() -> visited = true;
                }
            }
        }
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    root -> right -> right = new TreeNode(4);
    Solution solution;
    vector<int> rc = solution.preorderTraversal(root);
    cout << "solution.preorderTraversal:  ";
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    cout << "solution.inorderTraversal:   ";
    rc = solution.inorderTraversal3(root);
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
