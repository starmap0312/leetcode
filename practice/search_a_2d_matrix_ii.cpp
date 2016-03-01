/* - the problem can be solved via divide-and-conquer
 *   1) identify the middle (with respect to both row and column) elemenet
 *   2) compare the target with the middle element
 *      then at least the elements in one of the four quadrants can be eliminated
 * - time complexity:
 *   T(n) = 3T(n / 2) + c, where n denotes the dimension of the matrix
 *        = 3(3T(n / 4) + c) + c
 *        = 3(3(3T(n / 8) + c) + c) + c
 *        = ... (log n times)
 *        = O(c + 3c + 3^2 c + ... ) ... total log n terms
 *        = O(c * 3 ^ lg n)
 *        = O(n ^ lg 3)
 *       ~= O(n ^ 1.58)
 * - there exists a linear time algorithm: O(n) by stepping from the top-right corner of
 *   the matrix to its bottom-left corner, one step at a time
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        return search(matrix, target, 0, 0, matrix.size(), matrix[0].size());
    }

    bool search(vector<vector<int> >& matrix, int target, int startX, int startY,
        int endX, int endY) {
        if (startX >= endX || startY >= endY) return false;
        int midX = (startX + endX) / 2, midY = (startY + endY) / 2;
        if (matrix[midX][midY] == target) return true;
        else if (matrix[midX][midY] > target) {
            return search(matrix, target, startX, startY, midX, endY) ||
                search(matrix, target, startX, midY, midX, endY) ||
                search(matrix, target, midX, startY, endX, midY);
        } else {
            return search(matrix, target, midX + 1, midY + 1, endX, endY) ||
                search(matrix, target, startX, midY + 1, midX + 1, endY) ||
                search(matrix, target, midX + 1, startY, endX, midY + 1);
        }
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
