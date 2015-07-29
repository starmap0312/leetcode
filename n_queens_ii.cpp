/* function abs(int num) returns absolute value ==> abs(-5) == 5
 * vector<int> v; ==> use v.push_back(int) and v.pop_back(int) to push & pop back
 * vector<int> v; ==> define void func(const vector<int> &v) to make vector argument immutable
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveQueens(int n, int row, vector<int> queens) {
        if (row == n) {
            numSolutions++;
            return;
        }
        for (int column = 0; column < n; column++) {
            if (isSafe(row, column, queens)) {
                queens.push_back(column);
                solveQueens(n, row + 1, queens);
                queens.pop_back();
            }
        }
    }
    bool isSafe(int row, int column, const vector<int> &queens) {
        for (int i = 0; i < queens.size(); i++) {
            if (column == queens[i]) return false;
            if (abs(column - queens[i]) == abs(row - i)) return false;
        }
        return true;
    }

    int totalNQueens(int n) {
        vector<int> queens;
        solveQueens(n, 0, queens);
        return numSolutions;
    }
    Solution() : numSolutions(0) { }
private:
    int numSolutions;
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}
