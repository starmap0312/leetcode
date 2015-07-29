/* - always make sure to take integer overflow into consideration if the input values 
 *   contain INT_MIN or INT_MAX. transform the computation into type long to avoid
 *   integer overflow
 * - sometimes the overflow happens when comparing the addition of two numbers with 
 *   the other: ex. (a + b > c)?
 *   convert the comparison into: (a > c - b)? to avoid integer overflow
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
    bool isValidBST(TreeNode* root) {
       if (root == NULL) return true;
       long left_max = maximun(root -> left);
       long right_min = minimun(root -> right);
       if (left_max < (long)root -> val && (long)root -> val < right_min &&
           isValidBST(root -> left) && isValidBST(root -> right))
           return true;
       return false; 
    }
    long minimun(TreeNode* root) {
        if (root == NULL) return (long)INT_MAX + 1;
        return min((long)root -> val, min(minimun(root -> left), minimun(root -> right)));
    }
    long maximun(TreeNode* root) {
        if (root == NULL) return (long)INT_MIN - 1;
        return max((long)root -> val, max(maximun(root -> left), maximun(root -> right)));
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    Solution solution;
    cout << solution.isValidBST(root) << endl;
    return 0;
}
