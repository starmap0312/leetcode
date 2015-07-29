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
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesAcc(n, 0);
    }
    vector<TreeNode*> generateTreesAcc(int n, int acc) {
        vector<TreeNode*> results;
        if (n == 0) { 
            results.push_back(NULL); 
            return results; 
        } else if (n == 1) { 
            TreeNode *root = new TreeNode(acc + 1);
            results.push_back(root);
            return results;
        }
        for(int i = 0; i < n; i++) {
            vector<TreeNode*> leftTree = generateTreesAcc(i, acc);
            vector<TreeNode*> rightTree = generateTreesAcc(n - i - 1, acc + i + 1);
            for(int j = 0; j < leftTree.size(); j++) {
                for(int k = 0; k < rightTree.size(); k++) {
                    TreeNode *root = new TreeNode(acc + i + 1);
                    root -> left = copyTree(leftTree[j]);
                    root -> right = copyTree(rightTree[k]);
                    results.push_back(root);
                }
            }
        }
        return results;
    }
    TreeNode *copyTree(TreeNode *root) {
        if (root == NULL) return NULL;
        TreeNode *result = new TreeNode(root -> val);
        result -> left = copyTree(root -> left);
        result -> right = copyTree(root -> right);
        return result;
    }
};

int main() {
    Solution solution;
    solution.generateTrees(5);
    return 0;
}
