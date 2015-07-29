/* - the problem can be resolved by simple recursion which costs O(n) time in all cases
 *   if implement countLeaves() method for calculating the number of leaves via binary search
 *   the average time can be improved as for most cases the problem is resolved once the last 
 *   leaf is identified 
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
            return pow(2, leftDepth) + countLeaves(root, leftDepth, rightDepth) - 1; 
    }
    int countLeaves(TreeNode* root, int leftDepth, int rightDepth) {
        if (leftDepth == rightDepth) return pow(2, leftDepth);
        else if (rightDepth == 0) return leftDepth;
        int midRightDepth = findLeftmostDepth(root -> right);
        int midLeftDepth = findRightmostDepth(root -> left);
        if (midRightDepth == leftDepth)
            return countLeaves(root -> right, midRightDepth - 1, rightDepth - 1) + 
                pow(2, leftDepth - 1);
        else
            return countLeaves(root -> left, leftDepth - 1, midLeftDepth - 1);
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
