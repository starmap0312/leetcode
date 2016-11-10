/* - solve the problem via recursion 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() : numSolutions(0) { }

    void solveQueens(int size, int row, vector<int> solution) {
        // base case
        if (row == size) {
            numSolutions++;
            return;
        }
        // inductive case
        for (int col = 0; col < size; col++) {
            if (valid(row, col, solution)) {
                solution.push_back(col);
                solveQueens(size, row + 1, solution);
                solution.pop_back();
            }
        }
    }

    bool valid(int row, int col, const vector<int> &solution) {
        // the time of this step can be improved if we use two arrays for checking column & diagnal violations
        for (int i = 0; i < solution.size(); i++) {
            if (col == solution[i] || (col - row) == (solution[i] - i) || (row + col) == (i + solution[i])) {
                return false;
            }
        }
        return true;
    }

    int totalNQueens(int n) {
        vector<int> solution;
        solveQueens(n, 0, solution);
        return numSolutions;
    }

private:
    int numSolutions;
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}
