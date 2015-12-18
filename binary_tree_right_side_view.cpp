/* - use depth-first search to traverse the tree
 *   during the traversal compute the right side view vector: whenever there is a deeper level
 *   node appears during the traveral, push the node value into the vector
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
    Solution() : level(0) { }
    vector<int> rightSideView(TreeNode* root) {
        DFS(root);
        return result;
    }

    void DFS(TreeNode* itr) {
        if (itr == NULL) return;
        level++;
        if (level > result.size())
            result.push_back(itr -> val);
        DFS(itr -> right);
        DFS(itr -> left);
        level--;
    }

private:
    int level;
    vector<int> result;
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2), root -> right = new TreeNode(3);
    root -> left -> right = new TreeNode(5);
    root -> right -> right = new TreeNode(4);
    Solution solution;
    vector<int> result = solution.rightSideView(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
