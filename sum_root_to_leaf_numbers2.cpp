/* - convert C-string into integer ==> atoi("123") == 123, atoi("0123") == 123
 * - string s = "abc"; ==> by calling s.pop_back(), we get s == "ab", with last char removed
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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        else {
            pathSum(root, 0);
            return totalSum;
        }
    }
    void pathSum(TreeNode* root, int value) {
        if (root == NULL) return;
        value = value * 10 + root -> val;
        if (isLeaf(root)) {
            totalSum += value;
            return;
        }
        pathSum(root -> left, value);
        pathSum(root -> right, value);
    }
    bool isLeaf(TreeNode* root) {
        return (root -> left == NULL && root -> right == NULL);
    }
    Solution() : totalSum(0) { }
private:
    int totalSum;
};

int main() {
    TreeNode *root = new TreeNode(0);
    root -> left = new TreeNode(1); // root -> right = new TreeNode(3);
    Solution solution;
    cout << solution.sumNumbers(root) << endl;
    return 0;
}
