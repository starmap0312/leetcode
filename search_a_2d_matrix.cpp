/* - use binary search, first for finding the row and then the column
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int start = 0, end = matrix.size();
        while (start < end) {
            int middle = (start + end) / 2;
            if (matrix[middle][0] == target) return true;
            if (matrix[middle][0] > target) end = middle;
            else start = middle + 1;
        }
        int index = start - 1;
        if (index < 0) return false;
        start = 0, end = matrix[index].size();
        while (start < end) {
            int middle = (start + end) / 2;
            if (matrix[index][middle] == target) return true;
            if (matrix[index][middle] > target) end = middle;
            else start = middle + 1;
        }
        return false;
    }
};

int main() {
    int v[3][4] = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
    vector<int> v1(&v[0][0], &v[0][3]);
    vector<int> v2(&v[1][0], &v[1][3]);
    vector<int> v3(&v[2][0], &v[2][3]);
    vector<vector<int> > matrix;
    matrix.push_back(v1), matrix.push_back(v2), matrix.push_back(v3);
    Solution solution;
    cout << solution.searchMatrix(matrix, 3) << endl;
    cout << solution.searchMatrix(matrix, 9) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    cout << solution.searchMatrix(matrix, 23) << endl;
    return 0;
}
