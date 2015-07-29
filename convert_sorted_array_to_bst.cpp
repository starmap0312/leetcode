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
        return convert(nums, 0, nums.size());
    }
    TreeNode* convert(vector<int>& nums, int start, int end) {
        if (end - start <= 0) return NULL;
        int middle = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root -> left = convert(nums, start, middle);
        root -> right = convert(nums, middle + 1, end);
        return root;
    }
};

int main() {
    return 0;
}
