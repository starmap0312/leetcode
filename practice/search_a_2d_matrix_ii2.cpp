/* - the previous solution exceeds the time limit of leetcode
 *   one slight improvement is to reduce trivail recursions when startX = midX or startY = midY
 *   in these cases, only the elements of one row or column are searched
 *   therefore, instead of solving them in the recursion, we write simple while-loops to find target
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
        // if only one row or column need to be searched, we search them in while-loop
        // iterations, so that the overhead of recursive calls is reduced
        if (startX == midX) {
            int start = startY, end = endY;
            while (start < end) {
                int mid = (start + end) / 2;
                if (matrix[startX][mid] == target) return true;
                else if (matrix[startX][mid] < target) start = mid + 1;
                else end = mid;
            }
            return false;
        }
        if (startY == midY) {
            int start = startX, end = endX;
            while (start < end) {
                int mid = (start + end) / 2;
                if (matrix[mid][startY] == target) return true;
                else if (matrix[mid][startY] < target) start = mid + 1;
                else end = mid;
            }
            return false;

        }
        // solve the problem by recursions
        if (matrix[midX][midY] > target) {
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
