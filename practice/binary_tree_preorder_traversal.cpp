/* - simulate pre-order traversal using a stack
 *   i.e. push the root to the queue
 *        while the queue is not empty:
 *            pop the top node
 *            output the leftmost path from the top node
 *            during the visit of the leftmost path, push every right child to the queue
 */
#include <iostream>
#include <stack>
#include <vector>

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
        stack<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            q.pop();
            while (itr != NULL) {
                if (itr -> right != NULL)
                    q.push(itr -> right);
                result.push_back(itr -> val);
                itr = itr -> left;
            }
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
    return 0;
}
