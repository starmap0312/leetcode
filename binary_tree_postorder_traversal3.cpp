/* 
 */
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        pushLeftmostNodes(root);
        while (!s.empty()) {
            if (s.top().second == false) {
                s.top().second = true;
                pushLeftmostNodes(s.top().first -> right);
            } else {
                result.push_back(s.top().first -> val);
                s.pop();
            }
        }
        return result;
    }
    void pushLeftmostNodes(TreeNode *root) {
        while (root != NULL) {
            s.push(make_pair(root, false));
            root = root -> left;
        }
    }
private:
    stack<pair<TreeNode*, bool> > s;
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    Solution solution;
    vector<int> result = solution.postorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
