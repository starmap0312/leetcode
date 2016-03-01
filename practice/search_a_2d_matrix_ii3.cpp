/* - a step-wise linear search algorithm
 * - observe that when compare the target with the top-right corner element
 *   either we identify the number that is equal to the target immediately, or
 *   at least all the numbers in the row or all the numbers in the column can be
 *   eliminated from the solution
 *   in the later case, we can proceed to a smaller matrix with one column or one row
 *   removed
 *   proceeding in the manner until the target is identified or no candidate left in
 *   the matrix
 * - time complexity = O(n), where n is the dimenstion of the matrix
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};

int main() {
    int a1[] = {  1,  4,  7, 11, 15 };
    int a2[] = {  2,  5,  8, 12, 19 };
    int a3[] = {  3,  6,  9, 16, 22 };
    int a4[] = { 10, 13, 14, 17, 24 };
    int a5[] = { 18, 21, 23, 26, 30 };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 5));
    matrix.push_back(vector<int>(a2, a2 + 5));
    matrix.push_back(vector<int>(a3, a3 + 5));
    matrix.push_back(vector<int>(a4, a4 + 5));
    matrix.push_back(vector<int>(a5, a5 + 5));
    Solution solution;
    cout << solution.searchMatrix(matrix, 5) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    cout << solution.searchMatrix(matrix, 24) << endl;
    cout << solution.searchMatrix(matrix, 25) << endl;
    cout << solution.searchMatrix(matrix, 30) << endl;
    return 0;
}
