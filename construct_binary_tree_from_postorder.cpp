/* - vector<int> v; ==> use find(v.begin(), v.end(), 3) == v.end() to check if value 3
 *                      is in vector v. Note that find() returns an iterator to the
 *                      first element of vector v with value 3
 * - the problem is solved by recursion, note that the last element of postorder
 *   sequence indicates the root node, and search it in the inorder sequence gives
 *   the subsequences of left and right child
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        if (size == 0) return NULL;
        return build(inorder, postorder, 0, size, 0, size);
    }
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, 
        int i_start, int i_end, int p_start, int p_end) {
        if (i_start >= i_end) return NULL;
        vector<int>::iterator itr = find(inorder.begin() + i_start, 
            inorder.begin() + i_end, postorder[p_end - 1]);
        int i = itr - inorder.begin() - i_start;
        TreeNode *root = new TreeNode(postorder[p_end - 1]);
        root -> left = build(inorder, postorder, i_start, i_start + i, 
            p_start, p_start + i);
        root -> right = build(inorder, postorder, i_start + i + 1, i_end,
            p_start + i, p_end - 1);
        return root;
    }
};

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6 }, b[] = { 2, 4, 3, 1, 6, 5 };
    vector<int> inorder(a, a + 6);
    vector<int> postorder(b, b + 6);
    Solution solution;
    solution.buildTree(inorder, postorder);
    return 0;
}
