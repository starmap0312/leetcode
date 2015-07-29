#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int> >();
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level_result;
            queue<TreeNode*> q_next;
            while (!q.empty()) {
                level_result.push_back(q.front() -> val);
                if (q.front() -> left != NULL) q_next.push(q.front() -> left);
                if (q.front() -> right != NULL) q_next.push(q.front() -> right);
                q.pop();
            }
            result.push_back(level_result);
            q = q_next;
        }
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);
    Solution solution;
    vector<vector<int> > result = solution.levelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
