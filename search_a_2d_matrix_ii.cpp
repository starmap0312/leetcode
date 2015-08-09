/* 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return search(matrix, target, 0, 0, matrix.size(), matrix[0].size());
    }
    bool search(vector<vector<int> > &matrix, int target, int x1, int y1, int x2, int y2) {
        if (x1 >= x2 || y1 >= y2) return false;
        int mid_x = (x1 + x2) / 2, mid_y = (y1 + y2) / 2;
        if (x1 == mid_x) {
            int start = y1, end = y2;
            while (start < end) {
                int middle = (start + end) / 2;
                if (matrix[x1][middle] == target) return true;
                if (matrix[x1][middle] > target) end = middle;
                else start = middle + 1;
            }
            return false;
        }
        if (y1 == mid_y) {
            int start = x1, end = x2;
            while (start < end) {
                int middle = (start + end) / 2;
                if (matrix[middle][y1] == target) return true;
                if (matrix[middle][y1] > target) end = middle;
                else start = middle + 1;
            }
            return false;
        }
        if (matrix[mid_x][mid_y] == target) return true;
        else if (matrix[mid_x][mid_y] > target) {
            return search(matrix, target, x1, y1, mid_x, y2) ||
                   search(matrix, target, mid_x, y1, x2, mid_y);
        } else {
            return search(matrix, target, mid_x + 1, y1, x2, y2) ||
                   search(matrix, target, x1, mid_y + 1, mid_x + 1, y2);
        }
    }
};

int main() {
    int v[3][4] = {
        { 5, 6, 10, 14 }, 
        { 6, 10, 13, 18 }, 
        { 10, 13, 18, 19 }
    };
    vector<int> v1(&v[0][0], &v[0][4]);
    vector<int> v2(&v[1][0], &v[1][4]);
    vector<int> v3(&v[2][0], &v[2][4]);
    vector<vector<int> > matrix;
    matrix.push_back(v1), matrix.push_back(v2), matrix.push_back(v3);
    Solution solution;
    cout << solution.searchMatrix(matrix, 14) << endl;
    return 0;
}
