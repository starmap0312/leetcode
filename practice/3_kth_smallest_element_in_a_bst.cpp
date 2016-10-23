/* - the problem can be solved via recursion
 *   during the in-order traversal, we compute the current rank and continue until rank k is found 
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
    Solution() { }

    void kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
    }

    void traverse(TreeNode* root, int &rank) {
        // base case
        if (root == NULL) return;
        // inductive case
        traverse(root -> left, rank);
        rank--;
        if (rank == 0) {
            cout << root -> val << endl;
            return;
        }
        traverse(root -> right, rank);
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(3);
    root -> right = new TreeNode(7);
    Solution solution;
    solution.kthSmallest(root, 2);
    return 0;
}
