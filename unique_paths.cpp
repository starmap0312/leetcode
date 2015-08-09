/* - use dynamic programming to compute the number of unique paths
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > table(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) table[i][j] = 1;
                else table[i][j] = table[i][j - 1] + table[i - 1][j];
            }
        }
        return table[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    cout << solution.uniquePaths(3, 4) << endl;
    return 0;
}
