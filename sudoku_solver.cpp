#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        solve(board, 0);
    }

    bool solve(vector<vector<char> >& board, int n) {
        if (n == 9 * 9) return true;
        int i = n / 9, j = n % 9;
        if (board[i][j] != '.') {
            if (solve(board, n + 1)) return true;
        } else {
            for (int k = 0; k < 9; k++) {
                board[i][j] = (char)('1' + k);
                if (isValid(board, i, j) && solve(board, n + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool isValid(vector<vector<char> >& board, int i, int j) {
        return isValidCell(board, i, j) && isValidRow(board, i, j) &&
               isValidColumn(board, i, j);
    }

    bool isValidCell(vector<vector<char> >& board, int i, int j) {
        int row = (i / 3) * 3, column = (j / 3) * 3;
        for (int x = row; x < row + 3; x++)
            for (int y = column; y < column + 3; y++)
                if (x != i && y != j && board[i][j] == board[x][y]) return false;
        return true;
    }

    bool isValidRow(vector<vector<char> >& board, int i, int j) {
        for (int k = 0; k < board[i].size(); k++)
            if (k != j && board[i][j] == board[i][k]) return false;
        return true;
    }

    bool isValidColumn(vector<vector<char> >& board, int i, int j) {
        for (int k = 0; k < board.size(); k++)
            if (k != i && board[i][j] == board[k][j]) return false;
        return true;
    }
};

int main() {
    char r1[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.' };
    char r2[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.' };
    char r3[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.' };
    char r4[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3' };
    char r5[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1' };
    char r6[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6' };
    char r7[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.' };
    char r8[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5' };
    char r9[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9' };
    vector<vector<char> > board;
    board.push_back(vector<char>(r1, r1 + 9));
    board.push_back(vector<char>(r2, r2 + 9));
    board.push_back(vector<char>(r3, r3 + 9));
    board.push_back(vector<char>(r4, r4 + 9));
    board.push_back(vector<char>(r5, r5 + 9));
    board.push_back(vector<char>(r6, r6 + 9));
    board.push_back(vector<char>(r7, r7 + 9));
    board.push_back(vector<char>(r8, r8 + 9));
    board.push_back(vector<char>(r9, r9 + 9));
    Solution solution;
    solution.solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
