/* - rotating maps (i, j) to (matrix[i].size() - j, i)
 * - this approach uses O(m * n) extra space
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        vector<vector<int> > rotated(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                rotated[j][matrix[i].size() - i - 1] = matrix[i][j];
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                matrix[i][j] = rotated[i][j];
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
