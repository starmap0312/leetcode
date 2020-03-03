/* - the problem can be solved via dynamic programming:
 *   let answers[i][j] denote the number of unique paths from (0, 0) to (i, j)
 *   we have that answers[i][j] = answers[i - 1][j] + answers[i][j - 1]
 *   the boundary cases: answers[i][j] = 1 for i = 0 or j = 0
 * - a naive approach builds a m x n table, which takes O(mn) space
 *   a simple improvement takes O(n) space, as to fill out the answers of row i, we need only
 *   the answers of row i - 1
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<int> answers(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                answers[j] = answers[j - 1] + answers[j];
            }
        }
        return answers[n - 1];
    }
};

int main() {
    Solution solution;
    cout << solution.uniquePaths(3, 2) << endl;
    return 0;
}
