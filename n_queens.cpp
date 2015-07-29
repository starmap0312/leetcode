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
            solutions.push_back(queens);
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

    vector<vector<string> > solveNQueens(int n) {
        vector<int> queens;
        solveQueens(n, 0, queens);
        vector<vector<string> > results;
        for (int i = 0; i < solutions.size(); i++)
            results.push_back(convert_to_queen_strings(n, solutions[i]));
        return results;
    }

    vector<string> convert_to_queen_strings(int n, const vector<int> &solution) {
        vector<string> result;
        for (int i = 0; i < solution.size(); i++) 
            result.push_back(queen_string(n, solution[i]));
        return result;
    }

    string queen_string(int n, int column) {
        string result = "";
        for (int i = 0; i < n; i++) {
            if (i == column) result += 'Q';
            else result += '.';
        }
        return result;
    }
private:
    vector<vector<int> > solutions;
};

int main() {
    Solution solution;
    vector<vector<string> > result = solution.solveNQueens(4);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << endl;
        cout << endl << endl;
    }
    return 0;
}
