#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> q;
        TreeNode *dummy = new TreeNode(-1);
        dummy -> right = root;
        q.push(dummy);
        while (!q.empty()) {
            TreeNode *itr = q.top();
            q.pop();
            itr = itr -> right;
            while (itr != NULL) {
                q.push(itr);
                result.push_back(itr -> val);
                itr = itr -> left;
            }
        }
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    Solution solution;
    vector<int> rc = solution.preorderTraversal(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
