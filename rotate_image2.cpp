/* - rotating maps (i, j) to (matrix[i].size() - j, i)
 * - this approach improves the previous one by uses O(1) extra space
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < (matrix[i].size() + 1) / 2; j++) {
                int n = matrix[i].size() - 1;
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = tmp;
            }
        }
    }
};

int main() {
    int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(&a[0][0], &a[0][3]));
    matrix.push_back(vector<int>(&a[1][0], &a[1][3]));
    matrix.push_back(vector<int>(&a[2][0], &a[2][3]));
    Solution solution;
    solution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
