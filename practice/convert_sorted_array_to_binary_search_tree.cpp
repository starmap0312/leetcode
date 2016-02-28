/* - the problem can be solved via dynamic programming:
 *   first, decide the root of the tree, which has the middle value of the sorted array, and then 
 *   construct the left and right subtrees recursively
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }

    TreeNode* construct(vector<int>& nums, int beg, int end) {
        if (beg == end) return NULL;
        int mid = (beg + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = construct(nums, beg, mid);
        root -> right = construct(nums, mid + 1, end);
        return root;
    }
};

int main() {
    int a[] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);
    cout << root -> val << endl;
    cout << root -> left -> val << endl;
    cout << root -> right -> val << endl;
    return 0;
}
