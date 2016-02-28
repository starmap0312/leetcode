/* - the problem can be solved using a stack:
 *   1) push all the nodes of the leftmost path from the root to the stack
 *   2) pop the element of the stack one by one until it becomes empty
 *      after popping the top element, if it has a right child, push all the nodes of the leftmost
 *      path from its right child to the stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> q;
        TreeNode *itr = root;
        while (itr != NULL) {
            q.push(itr);
            itr = itr -> left;
        }
        while (!q.empty()) {
            TreeNode *node = q.top();
            q.pop();
            result.push_back(node -> val);
            TreeNode *itr = node -> right;
            while (itr != NULL) {
                q.push(itr);
                itr = itr -> left;
            }
        }
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(2);
    Solution solution;
    vector<int> rc = solution.inorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
