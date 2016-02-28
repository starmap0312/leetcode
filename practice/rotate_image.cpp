/* - given a matrix of n x n, observe that the rotation moves the following grids:
 *   (i, j) => (j, n  - 1 - i) => (n - i, n - 1 - j) => (n - 1 - j, i) => (i, j)
 * - Pairing the every 4 grids together, move initial parts of grids: 
 *   ex.
 *     x x x x x o
 *     o x x x o o
 *     o o x o o o
 *     o o o o o o
 *     o o o o o o
 *     o o o o o o
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

int main() {
    int a1[] = { 1, 2, 3 };
    int a2[] = { 4, 5, 6 };
    int a3[] = { 7, 8, 9 };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 3));
    matrix.push_back(vector<int>(a2, a2 + 3));
    matrix.push_back(vector<int>(a3, a3 + 3));
    Solution solution;
    solution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
