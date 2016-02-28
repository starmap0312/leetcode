/* - the problem can be solved via a 2-phases binary search
 *   first, binary search for the right row; next, binary search for the right column
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        // first binary search for the row
        int start = 0, end = matrix.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) end = mid;
            else start = mid + 1;
        }
        if (start == 0) return false;
        // first binary search for the column
        int left = 0, right = matrix[start - 1].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[start - 1][mid] == target) return true;
            else if (matrix[start - 1][mid] > target) right = mid;
            else left = mid + 1;
        }
        return false;
    }
};

int main() {
    int a1[] = { 1, 3, 5, 7 };
    int a2[] = { 10, 11, 16, 20 };
    int a3[] = { 23, 30, 34, 50 };
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(a1, a1 + 4));
    matrix.push_back(vector<int>(a2, a2 + 4));
    matrix.push_back(vector<int>(a3, a3 + 4));
    Solution solution;
    cout << solution.searchMatrix(matrix, 3) << endl;
    cout << solution.searchMatrix(matrix, 16) << endl;
    cout << solution.searchMatrix(matrix, 35) << endl;
    return 0;
}
