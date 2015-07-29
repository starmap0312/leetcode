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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        hasPathSum(root, sum, path);
        return result;
    }
    void hasPathSum(TreeNode* root, int sum, vector<int> &path) {
        if (root == NULL) return;
        sum -= root -> val;
        if (isLeaf(root)) {
            path.push_back(root -> val);
            if (sum == 0) result.push_back(path);
            path.pop_back();
        } else {
            path.push_back(root -> val);
            hasPathSum(root -> left, sum, path);
            hasPathSum(root -> right, sum, path);
            path.pop_back();
        }
    }
    bool isLeaf(TreeNode* node) {
        if (node -> left == NULL && node -> right == NULL) return true;
        else return false;
    }
private:
    vector<vector<int> > result;
};

int main() {

    return 0;
}
