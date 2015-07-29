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
    int maxPathSum(TreeNode* root) {
        findPathSum(root);
        return maxPath;
    }
    int findPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int leftPath = max(0, findPathSum(root -> left));
        int rightPath = max(0, findPathSum(root -> right));
        maxPath = max(maxPath, leftPath + rightPath + root -> val);
        return max(leftPath, rightPath) + root -> val;
    }
    Solution() : maxPath(INT_MIN) { }
private:
    int maxPath;
};

int main() {
    TreeNode *root = new TreeNode(-3);
    //TreeNode *root = new TreeNode(1);
    //root -> left = new TreeNode(2), root -> right = new TreeNode(3);
    Solution solution;
    cout << solution.maxPathSum(root) << endl;
    return 0;
}
