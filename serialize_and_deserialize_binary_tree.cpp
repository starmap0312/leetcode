/* - to serialize a tree, traverse the tree via breadth-first search
 *   use a queue (FIFO) to implement BFS
 *   initially, put root into the queue and then perform the following loop:
 *   ex. while (queue is not empty) {
 *           pop the front element out of the queue
 *           push its two children to the back of the queue
 *       }
 *   construct the serialized string during the traversal
 * - to deserialize a string, traverse the string from left to right
 *   use a queue (FIFO) during the traversal
 *   initially, extract first value read from the string and construct a node for it
 *   the first node created is the root. put it into the queue and then perform the following loop:
 *   ex. while (queue is not empty) {
 *           pop the front element out of the queue (parent node)
 *           extract next two values read from the string and then
 *           construct two nodes for them (left and right child nodes)
 *           construct the links between the nodes
 *           push the two nodes (if not NULL) to the back of the queue
 *       }
 */
#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            if (node == NULL) {
                result += "*,";
            } else {
                result += (to_string(node -> val) + ",");
                q.push(node -> left);
                q.push(node -> right);
            }
            q.pop();
        }
        return result.substr(0, result.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        TreeNode *root = getNode(data, pos);
        if (root == NULL) return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *parent = q.front();
            q.pop();
            TreeNode *node1 = getNode(data, pos);
            TreeNode *node2 = getNode(data, pos);
            parent -> left = node1;
            parent -> right = node2;
            if (node1 != NULL) q.push(node1);
            if (node2 != NULL) q.push(node2);
        }
        return root;
    }

    TreeNode *getNode(string &data, int &pos) {
        string value = getValue(data, pos);
        if (value != "*")
            return new TreeNode(atoi(value.c_str()));
        return NULL;
    }

    string getValue(string &data, int &pos) {
        int nextPos = data.find(',', pos);
        string result;
        if (nextPos == string::npos)
            result = data.substr(pos);
        else
            result = data.substr(pos, nextPos - pos);
        pos = ((nextPos == string::npos)? nextPos: nextPos + 1);
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2), root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(4), root -> right -> right = new TreeNode(5);
    Codec codec;
    string data = codec.serialize(root);
    cout << data << endl;
    TreeNode *rc = codec.deserialize(data);
    cout << codec.serialize(rc) << endl;
    return 0;
}
