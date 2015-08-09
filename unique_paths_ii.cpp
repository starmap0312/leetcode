/* - to initialize a two-dimentional vector v with size 3 * 4:
 *   vector<vector<int> > v(3, vector<int>(4));
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > table(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) table[i][j] = 0;
                else if (i == 0) {
                    if (j == 0) table[i][j] = 1;
                    else table[i][j] = (table[i][j - 1] == 0? 0: 1);
                } else if (j == 0) {
                    table[i][j] = (table[i - 1][j] == 0? 0: 1);
                } else {
                    int num1 = (obstacleGrid[i][j - 1] == 1? 0: table[i][j - 1]);
                    int num2 = (obstacleGrid[i - 1][j] == 1? 0: table[i - 1][j]);
                    table[i][j] = num1 + num2;
                }
            }
        }
        return table[m - 1][n - 1];
    }
};

int main() {
    int v[3][3] = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
    vector<vector<int> > grid;
    grid.push_back(vector<int>(&v[0][0], &v[0][3]));
    grid.push_back(vector<int>(&v[1][0], &v[1][3]));
    grid.push_back(vector<int>(&v[2][0], &v[2][3]));
    Solution solution;
    cout << solution.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
