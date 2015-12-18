/* - use a full binary tree to solve the problem, in which each internal node stores the total
 *   sum of the leaves in its subtree
 *   ex.          9
 *            4       5
 *          1   3   5   0  -> nums[3] = { 1, 3, 5 };
 *         [0] [1] [2] [3] -> index
 * - querying a range sum takes O(log n) time to trace two leaf nodes to the root node:
 *   sum up the numbers of corresponding leaf nodes and internal nodes
 *   ex.          9
 *            4       5
 *         (1) (3) (5)  0 -> sumRange(0, 2) = 1 + 3 + 5
 *         [0] [1] [2] [3] -> index
 * - updating the tree takes O(log n) time: update from leaf node to the root
 *   ex.         (16)
 *           (11)     5
 *          1  (10) 5   0 -> update(1, 10)
 *         [0] [1] [2] [3] -> index
 */
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node(int n) : val(n), left(NULL), right(NULL), parent(NULL) { }
    int val;
    Node *left, *right, *parent;
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        for (int i = 0; i < powerTwo(nums.size()); i++)
            if (i < nums.size()) leaves.push_back(new Node(nums[i]));
            else leaves.push_back(new Node(0));
        vector<Node *> nodes = leaves;
        while (nodes.size() > 1) {
            vector<Node *> next;
            for (int i = 0; i < nodes.size(); i += 2) {
                Node *node = new Node(nodes[i] -> val + nodes[i + 1] -> val);
                node -> left = nodes[i], node -> right = nodes[i + 1];
                nodes[i] -> parent = node, nodes[i + 1] -> parent = node;
                next.push_back(node);
            }
            nodes = next;
        }
        root = nodes[0];
    }

    int powerTwo(int n) {
        int result = 1;
        while (result <= n - 1)
            result = result << 1;
        return result;
    }

    void update(int i, int val) {
        Node *itr = leaves[i];
        int diff = val - itr -> val;
        while (itr != root) {
            itr -> val += diff;
            itr = itr -> parent;
        }
        root -> val += diff;
    }

    int sumRange(int i, int j) {
        if (leaves.size() == 0) return 0;
        if (i == j) return leaves[i] -> val;
        Node *itr1 = leaves[i], *itr2 = leaves[j];
        int sum = itr1 -> val + itr2 -> val;
        while (itr1 -> parent != root && itr1 -> parent != itr2 -> parent) {
            if (itr1 -> parent -> right != itr1)
                sum += itr1 -> parent -> right -> val;
            if (itr2 -> parent -> left != itr2)
                sum += itr2 -> parent -> left -> val;
            itr1 = itr1 -> parent;
            itr2 = itr2 -> parent;
        }
        return sum;
    }

private:
    vector<Node *> leaves;
    Node *root;
};

int main() {
    int a[] = { 1, 3, 5 };
    vector<int> nums(a, a + 3);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
    return 0;
}
