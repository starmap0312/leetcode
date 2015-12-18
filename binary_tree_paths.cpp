/* - traverse the tree via depth-first search
 *   during the traversal maintain the path from root to the current node
 *   output the path at each leaf node
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode *> path;
        DFS(root, path);
        return result;
    }

    void DFS(TreeNode* itr, vector<TreeNode *> &path) {
        if (itr == NULL) return;
        path.push_back(itr);
        if (itr -> left == NULL && itr -> right == NULL)
            result.push_back(toString(path));
        DFS(itr -> left, path);
        DFS(itr -> right, path);
        path.pop_back();
    }

    string toString(vector<TreeNode *> &path) {
        string result = "";
        for (int i = 0; i < path.size() - 1; i++)
            result += (to_string(path[i] -> val) + "->");
        result += to_string(path.back() -> val);
        return result;
    }

private:
    vector<string> result;
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2), root -> right = new TreeNode(3);
    root -> left -> right = new TreeNode(5);
    Solution solution;
    vector<string> rc = solution.binaryTreePaths(root);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
