/* - the problem can be solved via dynamic programming:
 *   number of unique BSTs of size k can be obtained using number of unique BSTs of size 0, 1, ..., k - 1
 * - we choose among 1, 2, ..., k to be the root, once the root is determined:
 *   note that: number of unique BSTs = product of numbers of unique BSTs of two subtrees
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> answers(1, 1);
        // let answers[i] be number of unique BSTs of size i
        for (int i = 1; i <= n; i++) { // let i be the size of the tree
            int numTrees = 0;
            for (int j = 0; j < i; j++) { // let j be the size of its left subtree
                numTrees += (answers[j] * answers[i - j - 1]);
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
