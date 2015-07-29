/* - use iteration for postorder traversal: simulate recursion by using stack
 *   nodes whose left child traversed but right child not traversed yet are put into
 *   the stack. when leftmost path nodes are all traversed, pick the top node of
 *   the stack and traverse its right child
 * - the problem is related to the binary search tree iterator problem
 * - stack<pair<int, int> > s; ==> when access the top element of the stack, i.e.
 *                                 pair<int, int> a = s.top(); variable a is a copy
 *                                 of the top element, so any change to a.first and
 *                                 a.second will not reflect on the original top element,
 *                                 so use pair<int*, int*> for the stack element instead
 *                                 if modifying the stack element is needed, or use
 *                                 s.top().first = 2, s.top().second() = 3 to directly
 *                                 modifying the element
 *
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
            pair<TreeNode*, bool*> itr = s.top();
            if (*itr.second == false) {
                *itr.second = true;
                pushLeftmostNodes(itr.first -> right);
            } else {
                result.push_back(itr.first -> val);
                s.pop();
            }
        }
        return result;
    }
    void pushLeftmostNodes(TreeNode *root) {
        while (root != NULL) {
            bool* traversed = new bool;
            *traversed = false;
            s.push(make_pair(root, traversed));
            root = root -> left;
        }
    }
private:
    stack<pair<TreeNode*, bool*> > s;
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
