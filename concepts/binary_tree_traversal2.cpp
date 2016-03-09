/* 
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.top();
            result.push_back(node -> val);
            q.pop();
            if (node -> right != NULL) {
                q.push(node -> right);
            }
            if (node -> left != NULL) {
                q.push(node -> left);
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> q;
        TreeNode *cur = root;
        while (true) {
            while (cur != NULL) {
                q.push(cur);
                cur = cur -> left;
            }
            if (q.empty()) break;
            TreeNode *node = q.top();
            q.pop();
            result.push_back(node -> val);
            cur = node -> right;
        }
        return result;
    }

    // postorder is the reversion of the preorder traversal
    // we revert the traversal and uses a stack for storing the output
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
        while (!output.empty()) {
            result.push_back(output.top());
            output.pop();
        }
        return result;
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