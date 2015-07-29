/* - class constructor initialization ==> TreeNode(int v1, int v2) : value1(v1), value2(v2) { }
 * - swap function ==> swap(int num1, int num2);
 */
#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution(): prevVal(INT_MIN), first(NULL), second(NULL), prevNode(NULL) { }
    void recoverTree(TreeNode* root) {
        traverseTree(root);
        swap(first -> val, second -> val);
    }
    void traverseTree(TreeNode* root) {
        if (root == NULL) return;
        traverseTree(root -> left);
        if (prevVal > root -> val) {
            if (second == NULL) first = prevNode;
            second = root;
        }
        prevVal = root -> val;
        prevNode = root;
        traverseTree(root -> right);
    }
private:
    TreeNode *first, *second, *prevNode;
    int prevVal;
};

int main() {

    return 0;
}
