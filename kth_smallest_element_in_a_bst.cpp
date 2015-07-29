/* - perform in-order traversal of the input tree and maintain the current rank
 *   during traversal, remember the value of the kth rank node
 */
#include <iostream>

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
    int kthSmallest(TreeNode* root, int k) {
        findKth(root, k);
        return value;
    }
    void findKth(TreeNode* root, int k) {
        if (root == NULL) return;
        findKth(root -> left, k);
        if (++count == k) {
            value = root -> val;
            return;
        }
        findKth(root -> right, k);
    }
    Solution() : count(0), value(0) { }
private:
    int count, value;
};

int main() {
    TreeNode *root = new TreeNode(5);
    root -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(3);
    root -> right = new TreeNode(6);
    Solution solution;
    cout << solution.kthSmallest(root, 3) << endl;
    return 0;
}
