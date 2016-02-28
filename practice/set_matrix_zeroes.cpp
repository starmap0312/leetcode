/* - a straightforward approach is to use O(m + n) extra space:
 *     a row vector for recording the indcies that contain a zero
 *     a column vector for recording the indices that contain a zero
 *   ex.
 *             0  1  0  1  --> a row vector
 *
 *       0     0  1  1  1
 *       0     1  1  0  1
 *       1     1  1  1  1
 *       ^
 *       |
 *    a column vector
 *
 *     after setting zeros:
 *
 *             0  1  0  1
 *
 *       0     0  0  0  0
 *       0     0  0  0  0
 *       1     0  1  0  1
 *
 * - an improved algorithm is to use O(1) extra space
 *   we use the first row and the first column of the matrix to achieve the same effect
 *   this requires two extra flags indicating whether the first row and first column any zero
 *   using the updated first row and updated first column to set zeros of the rest of the matrix
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        bool firstRowHasZero = false, firstColumnHasZero = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) firstColumnHasZero = true;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) firstRowHasZero = true;
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if (firstColumnHasZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if (firstRowHasZero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main() {
    int a1[] = { 0, 1, 1, 1 };
    int a2[] = { 1, 1, 0, 1 };
    int a3[] = { 1, 1, 1, 1 };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 4));
    matrix.push_back(vector<int>(a2, a2 + 4));
    matrix.push_back(vector<int>(a3, a3 + 4));
    Solution solution;
    solution.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
