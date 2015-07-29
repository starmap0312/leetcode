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
            vector<int> nums;
            nums.push_back(root -> val);
            pathSum(root, nums);
            return totalSum;
        }
    }
    void pathSum(TreeNode* root, vector<int> &nums) {
        if (root == NULL) return;
        if (isLeaf(root)) {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
                sum = sum * 10 + nums[i];
            totalSum += sum;
        } else {
            if (root -> left != NULL) {
                nums.push_back(root -> left -> val);
                pathSum(root -> left, nums);
                nums.pop_back();
            }
            if (root -> right != NULL) {
                nums.push_back(root -> right -> val);
                pathSum(root -> right, nums);
                nums.pop_back();
            }
        }
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
