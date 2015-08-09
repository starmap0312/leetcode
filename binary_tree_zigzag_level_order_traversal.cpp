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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        vector<TreeNode*> q;
        bool reverse = true;
        if (root == NULL) return result;
        q.push_back(root);
        while (!q.empty()) {
            vector<int> list;
            vector<TreeNode*> nextq;
            for (int i = 0; i < q.size(); i++) {
                if (q[i] -> left != NULL)
                    nextq.push_back(q[i] -> left);
                if (q[i] -> right != NULL)
                    nextq.push_back(q[i] -> right);
                if (reverse) list.push_back(q[i] -> val);
                else list.insert(list.begin(), q[i] -> val);
            }
            result.push_back(list);
            q = nextq;
            reverse = !reverse;
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    Solution solution;
    vector<vector<int> > result = solution.zigzagLevelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
