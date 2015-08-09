#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > result(n, vector<int>(n));
        int state = 0, x = n - 1, y = n;
        int counter = 1;
        int i = 0, j = -1;
        while (x >= 0 && y >= 0) {
            if (state % 4 == 0) {
                for (int k = 0; k < y; k++) {
                    j++;
                    result[i][j] = counter;
                    counter++;
                }
                y--;
            } else if (state % 4 == 1) {
                for (int k = 0; k < x; k++) {
                    i++;
                    result[i][j] = counter;
                    counter++;
                }
                x--;
            } else if (state % 4 == 2) {
                for (int k = 0; k < y; k++) {
                    j--;
                    result[i][j] = counter;
                    counter++;
                }
                y--;
            } else {
                for (int k = 0; k < x; k++) {
                    i--;
                    result[i][j] = counter;
                    counter++;
                }
                x--;
            }
            state++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.generateMatrix(3);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
