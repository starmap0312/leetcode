#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > matrix(n, vector<int>(n));
        int state = 0, x = n - 1, y = n;
        int counter = 1;
        int i = 0, j = -1;
        while (x >= 0 && y >= 0) {
            if (state % 4 == 0) {
                for (int k = 0; k < y; k++) {
                    j++;
                    matrix[i][j] = counter;
                    counter++;
                }
                y--;
            } else if (state % 4 == 1) {
                for (int k = 0; k < x; k++) {
                    i++;
                    matrix[i][j] = counter;
                    counter++;
                }
                x--;
            } else if (state % 4 == 2) {
                for (int k = 0; k < y; k++) {
                    j--;
                    matrix[i][j] = counter;
                    counter++;
                }
                y--;
            } else {
                for (int k = 0; k < x; k++) {
                    i--;
                    matrix[i][j] = counter;
                    counter++;
                }
                x--;
            }
            state++;
        }
        return matrix;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > matrix = solution.generateMatrix(3);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
