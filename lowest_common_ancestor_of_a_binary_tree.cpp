/* - perform depth-first search to find the two paths from root to two specified nodes
 *   traverse the two paths simultaneously to find the lowest common ancestor
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1, path2;
        findNode(root, p, path1);
        findNode(root, q, path2);
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++)
            if (path1[i] != path2[i]) break;
        if (i == 0) return NULL;
        else return path1[i - 1];
    }

    bool findNode(TreeNode* itr, TreeNode *p, vector<TreeNode *> &path) {
        if (itr == NULL) return false;
        path.push_back(itr);
        if (itr == p) return true;
        if (findNode(itr -> left, p, path)) return true;
        if (findNode(itr -> right, p, path)) return true;
        path.pop_back();
        return false;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root -> left = new TreeNode(5), root -> right = new TreeNode(1);
    root -> left -> left = new TreeNode(6), root -> left -> right = new TreeNode(2);
    root -> left -> right -> left = new TreeNode(7);
    root -> left -> right -> right = new TreeNode(4);
    root -> right -> left = new TreeNode(0), root -> right -> right = new TreeNode(8);
    TreeNode *p = root -> left, *q = root -> left -> right -> right;
    Solution solution;
    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    cout << lca -> val << endl;
    return 0;
}
