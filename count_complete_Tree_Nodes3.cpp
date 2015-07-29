/* 
 */
#include <iostream>
#include <cmath>

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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = findLeftmostDepth(root -> left);
        int rightDepth = findRightmostDepth(root -> right);
        if (leftDepth == rightDepth)
            return pow(2, leftDepth + 1) - 1;
        else
            return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
    int findLeftmostDepth(TreeNode* root) {
        int depth = 0;
        while (root != NULL) {
            depth++;
            root = root -> left;
        }
        return depth;
    }
    int findRightmostDepth(TreeNode* root) {
        int depth = 0;
        while (root != NULL) {
            depth++;
            root = root -> right;
        }
        return depth;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    Solution solution;
    cout << solution.countNodes(root) << endl;
    return 0;
}
