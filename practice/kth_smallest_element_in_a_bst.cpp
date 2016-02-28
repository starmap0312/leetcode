/* - the problem can be solved during the in-order traversal of the tree
 *   while the algorithm finishes the traversal of the left tree, the rank of the current root
 *   can be computed; therefore, an equality check of the rank against the value k is performed
 *   and the traversal will be terminated if the equality condition is met
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
    Solution() : rank(0) { }

    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return answer;
    }

    void find(TreeNode* root, int k) {
        if (root == NULL) return;
        find(root -> left, k);
        rank++;
        if (rank == k) {
            answer = root -> val;
            return;
        }
        find(root -> right, k);
    }

private:
    int rank, answer;
};

int main() {
    TreeNode *root = new TreeNode(5);
    root -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(3);
    root -> right = new TreeNode(7);
    Solution solution;
    cout << solution.kthSmallest(root, 4) << endl;
    return 0;
}
