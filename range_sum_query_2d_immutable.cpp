/* - compute the prefixSum matrix which sums up all the numbers from the upper-left corner to
 *   the current position
 * - the range sum query can be answered by querying the prefixSum matrix 4 times at most
 * - the preprocessing time and space are O(n ^ 2), whereas the query time is O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            prefixSum.push_back(vector<int>());
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                if (i == 0) prefixSum[i].push_back(sum);
                else prefixSum[i].push_back(prefixSum[i - 1][j] + sum);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int upperLeft = 0, upperRight = 0, lowerLeft = 0, lowerRight = prefixSum[row2][col2];
        if (row1 > 0 && col1 > 0) upperLeft = prefixSum[row1 - 1][col1 - 1];
        if (row1 > 0) upperRight = prefixSum[row1 - 1][col2];
        if (col1 > 0) lowerLeft = prefixSum[row2][col1 - 1];
        return upperLeft + lowerRight - upperRight - lowerLeft;
    }

private:
    vector<vector<int> > prefixSum;
};

int main() {
    int a1[] = { 3, 0, 1, 4, 2 };
    int a2[] = { 5, 6, 3, 2, 1 };
    int a3[] = { 1, 2, 0, 1, 5 };
    int a4[] = { 4, 1, 0, 1, 7 };
    int a5[] = { 1, 0, 3, 0, 5 };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 5));
    matrix.push_back(vector<int>(a2, a2 + 5));
    matrix.push_back(vector<int>(a3, a3 + 5));
    matrix.push_back(vector<int>(a4, a4 + 5));
    matrix.push_back(vector<int>(a5, a5 + 5));
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
