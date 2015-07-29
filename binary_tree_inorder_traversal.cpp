/* - use recursion for inorder traversal
 */
#include <iostream>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode* root, vector<int> &result) {
        if (root == NULL) return;
        traverse(root -> left, result);
        result.push_back(root -> val);
        traverse(root -> right, result);
    }
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
