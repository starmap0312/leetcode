/* - construct the matrix in the spiral order
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n)); // initialize an array of n x n
        int i = 0, j = -1; // initial position
        int x1 = -1, y1 = -1, x2 = n, y2 = n; // initial boundaries: [x1, x2] x [y1, y2]
        int direction = 0, count = 1;
        while (true) {
           if (direction % 4 == 0) { // +y
               if (j + 1 < y2) {
                   matrix[i][++j] = count;
                   count++;
               } else {
                  if (i + 1 >= x2) break;
                  x1++;
                  direction++;
               }
           } else if (direction % 4 == 1) { // +x
               if (i + 1 < x2) {
                   matrix[++i][j] = count;
                   count++;
               } else {
                  if (j - 1 <= y1) break;
                  y2--;
                  direction++;
               }
           } else if (direction % 4 == 2) { // -y
               if (j - 1 > y1) {
                   matrix[i][--j] = count;
                   count++;
               } else {
                  if (i - 1 <= x1) break;
                  x2--;
                  direction++;
               }
           } else { // -x
               if (i - 1 > x1) {
                   matrix[--i][j] = count;
                   count++;
               } else {
                  if (j + 1 >= y2) break;
                  y1++;
                  direction++;
               }
           }
        }
        return matrix;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > rc = solution.generateMatrix(4);
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++)
            cout << rc[i][j] << " ";
        cout << endl;
    }
    return 0;
}
