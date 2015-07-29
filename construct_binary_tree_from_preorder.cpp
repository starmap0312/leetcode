/* - vector<int> v; ==> v.push_back(3), v.pop_back(), v.empty(), v.begin(), v.end()
 *                      v.insert(v.begin() + i), v.erase(v.begin() + i)
 *                      v.find(v.begin(), v.end(), 3) != v.end()
 * - map<int, string> v; ==> v.empty(), v.begin(), v.end()
 *                           v[key] = value, v.find(key) != v.end()
 *   map<int, string>::iterator itr; ==> itr points to a pair, so to access simply use
 *                                       (itr -> first, itr-> second) == (key, value)
 * - stack<int> v; ==> v.push(3), v.pop(), v.empty(), v.top()
 * - queue<int> v; ==> v.push(3), v.pop(), v.empty(), v.front()
 * - string v; ==> v.empty(), v.begin(), v.end(), v.find("substring") != string::npos
 *                 v.substr(index, length), v.c_str()
 * - pair<int, string> v(1, "abc"); ==> to access simply use (v.first, v.second)
 *   pair<int, string> u = make_pair(1, string("abc")); => to access use (u.first, u.second)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreePosition(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    TreeNode* buildTreePosition(vector<int>& preorder, vector<int>& inorder, 
        int pre_beg, int pre_end, int in_beg, int in_end) {
        if (pre_beg == pre_end) return NULL;
        int found = findElement(inorder, in_beg, in_end, preorder[pre_beg]);
        TreeNode* root = new TreeNode(preorder[pre_beg]);
        root -> left = buildTreePosition(preorder, inorder, 
            pre_beg + 1, pre_beg + found - in_beg + 1, in_beg, found);
        root -> right = buildTreePosition(preorder, inorder, 
            pre_beg + found - in_beg + 1, pre_end, found + 1, in_end);
        return root;
    }
private:
    int findElement(vector<int>& inorder, int beg, int end, int num) {
        vector<int>::iterator itr = find(inorder.begin() + beg, inorder.begin() + end, num);
        return itr - inorder.begin();
    }
};

int main() {
    vector<int> v, u;
    v.push_back(1), v.push_back(2), u.push_back(2), u.push_back(1);
    Solution solution;
    solution.buildTree(v, u);
    return 0;
}
