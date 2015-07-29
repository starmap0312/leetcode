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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        sum -= root -> val;
        if (isLeaf(root)) {
            if (sum == 0) return true;
            else return false;
        }
        if (hasPathSum(root -> left, sum) || hasPathSum(root -> right, sum))
            return true;
        return false;
    }
    bool isLeaf(TreeNode* node) {
        if (node -> left == NULL && node -> right == NULL) return true;
        else return false;
    }
};

int main() {

    return 0;
}
