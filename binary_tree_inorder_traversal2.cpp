/* - use iteration and stack for inorder traversal
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
        pushLeftmostNodes(root);
        while (!s.empty()) {
            TreeNode *itr = s.top();
            s.pop();
            result.push_back(itr -> val);
            pushLeftmostNodes(itr -> right);
        }
        return result;
    }
    void pushLeftmostNodes(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            root = root -> left;
        }
    }
private:
    stack<TreeNode*> s;
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(2);
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
