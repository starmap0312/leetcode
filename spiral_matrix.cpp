#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        if (matrix.size() == 1) return matrix[0];
        int state = 0, x = matrix.size() - 1, y = matrix[0].size();
        int i = 0, j = -1;
        while (x >= 0 && y >= 0) {
            if (state % 4 == 0) {
                for (int k = 0; k < y; k++) {
                    j++;
                    result.push_back(matrix[i][j]);
                }
                y--;
            } else if (state % 4 == 1) {
                for (int k = 0; k < x; k++) {
                    i++;
                    result.push_back(matrix[i][j]);
                }
                x--;
            } else if (state % 4 == 2) {
                for (int k = 0; k < y; k++) {
                    j--;
                    result.push_back(matrix[i][j]);
                }
                y--;
            } else {
                for (int k = 0; k < x; k++) {
                    i--;
                    result.push_back(matrix[i][j]);
                }
                x--;
            }
            state++;
        }
        return result;
    }
};

int main() {
    int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(&a[0][0], &a[0][3]));
    matrix.push_back(vector<int>(&a[1][0], &a[1][3]));
    matrix.push_back(vector<int>(&a[2][0], &a[2][3]));
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
    return 0;
}
