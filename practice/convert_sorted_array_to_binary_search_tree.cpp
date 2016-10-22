/* - the problem can be solved via dynamic programming:
 *   first, decide the root of the tree, which has the middle value of the sorted array
 *   next, construct the left and right subtrees recursively
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
    TreeNode* sortedArrayToBST(vector<int>& sorted) {
        return construct(sorted, 0, sorted.size());
    }

    TreeNode* construct(vector<int>& sorted, int start, int end) {
        if (start == end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(sorted[mid]);
        root -> left = construct(sorted, start, mid);
        root -> right = construct(sorted, mid + 1, end);
        return root;
    }
};

int main() {
    int a[] = { 1, 2, 3 };
    vector<int> sorted(a, a + 3);
    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(sorted);
    cout << root -> val << endl;
    cout << root -> left -> val << endl;
    cout << root -> right -> val << endl;
    return 0;
}
