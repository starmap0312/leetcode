/* - the problem can be solved via dynamic programming:
 *   let answers[i][j] denote the minimum path sum from grid[0][0] to grid[i][j]
 *   note that: answers[i][j] = min(answers[i - 1][j], answers[i][j - 1]) + grid[i][j]
 * - handle the boundary cases where i = 0 or j = 0
 * - the space can be reduced to O(n) by just maintaining the answers of the previous row
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> answers;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0) {
                    if (j == 0) answers.push_back(grid[i][j]);
                    else answers.push_back(answers[j - 1] + grid[i][j]);
                } else {
                    if (j == 0) answers[j] = answers[j] + grid[i][j];
                    else answers[j] = min(answers[j - 1], answers[j]) + grid[i][j];
                }
            }
        }
        return answers.back();
    }
};

int main() {
    int a1[] = { 1, 0, 1 };
    int a2[] = { 2, 3, 1 };
    int a3[] = { 0, 0, 1 };
    vector<vector<int> > grid;
    grid.push_back(vector<int>(a1, a1 + 3));
    grid.push_back(vector<int>(a2, a2 + 3));
    grid.push_back(vector<int>(a3, a3 + 3));
    Solution solution;
    cout << solution.minPathSum(grid) << endl;
    return 0;
}
