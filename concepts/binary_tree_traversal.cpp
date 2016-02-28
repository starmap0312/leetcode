/* - during the depth-first traversal of the tree, use a stack to stores the roots
 *   whose right subtrees have not yet been traversed
 * - we need to create a dummy node whose right child is set to be the input root
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
