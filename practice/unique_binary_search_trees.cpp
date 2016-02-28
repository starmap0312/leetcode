/* - the problem can be solved via dynamic programming:
 *   to find the number of unique binary search trees of size k, one can rely on the answers to
 *   the number of unique binary search trees of size 0, 1, ..., k - 1
 *   specifically, one can chooses among 1, 2, ..., k which to be put in the root, which results
 *   in two subtrees of size smaller than k, and the number of ways to contruct a binary search
 *   tree with the root determined is equal to the product of the numbers of binary search trees
 *   of two subtrees
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> answers(1, 1);
        // answers[i] denotes the number of unique binary search trees of size i
        for (int i = 1; i <= n; i++) { // let i be the size of the tree
            int numTrees = 0;
            for (int j = 0; j < i; j++) { // let j be the size of its left subtree
                numTrees += answers[j] * answers[i - j - 1];
            }
            answers.push_back(numTrees);
        }
        return answers[n];
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}
