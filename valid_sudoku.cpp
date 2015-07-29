/* - // exhaustive searching for a solution using recursions
 *   bool solve(int index) {
 *       for (all possible choices at index) {
 *           make a choice
 *           if (solve(index + 1)) return true; // recursively solve the next index and terminates
 *           un-make the choice                 // if subsequent sub-problems can be solved
 *       }
 *   }
 * - // exhaustive searching for all solutions using recursions
 *   bool solve(int index) {
 *       for (all possible choices at index) {
 *           make a choice
 *           solve(index + 1);                  // recursively solve the next index and all
 *           un-make the choice                 // possible choices will be made and traversed
 *       }
 *   }
 * - think about the above two paradigms as decending down a decision tree, at each node
 *   a list of children represent the possible choices to be made
 *   searching for a solution looks for a path from root to leaf that returns true, whereas
 *   searching for all solutions traverses all the paths from root to all the leaves
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        return isValid(0, board);
    }

    bool isValid(int index, vector<vector<char> >& board) {
        if (index == board.size() * board.size()) return true;
        int row = getRow(index, board), column = getColumn(index, board);
        if (board[row][column] != '.') {
            if (isSafe(index, board) && isValid(index + 1, board)) return true;
        } else {
            for (int i = (int)'1'; i <= (int)'9'; i++) {
                board[row][column] = (char)i;
                //cout << "(" << row << ", " << column << ") = " << board[row][column] << endl;
                if (isSafe(index, board) && isValid(index + 1, board)) return true;
                board[row][column] = '.';
            }
        }
        return false;
    }

    bool isSafe(int index, vector<vector<char> >& board) {
        return isRowSafe(index, board) && isColumnSafe(index, board) && isBoxSafe(index, board);
    }

    bool isRowSafe(int index, vector<vector<char> >& board) {
        int row = getRow(index, board), column = getColumn(index, board);
        for (int i = 0; i < board.size(); i++)
            if (i != column && board[row][i] == board[row][column]) return false;
        return true;
    }

    bool isColumnSafe(int index, vector<vector<char> >& board) {
        int row = getRow(index, board), column = getColumn(index, board);
        for (int i = 0; i < board.size(); i++)
            if (i != row && board[i][column] == board[row][column]) return false;
        return true;
    }

    bool isBoxSafe(int index, vector<vector<char> >& board) {
        int row = getRow(index, board), column = getColumn(index, board);
        int cornerRow = getCornerRow(index, board); 
        int cornerColumn = getCornerColumn(index, board);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (cornerRow + i != row && cornerColumn + j != column &&
                    board[cornerRow + i][cornerColumn + j] == board[row][column]) return false;
        return true;
    }

    int getRow(int index, vector<vector<char> >& board) {
        return index / board.size();
    }

    int getColumn(int index, vector<vector<char> >& board) {
        return index % board.size();
    }

    int getCornerRow(int index, vector<vector<char> >& board) {
        return (getRow(index, board) / 3) * 3;
    }

    int getCornerColumn(int index, vector<vector<char> >& board) {
        return (getColumn(index, board) / 3) * 3;
    }
};

vector<char> parse(string s) {
    vector<char> result;
    for (int i = 0; i < s.size(); i++)
        result.push_back(s[i]);
    return result;
}

vector<vector<char> > parse_input(string input[]) {
    vector<vector<char> > result;
    for (int i = 0; i < 9; i++)
        result.push_back(parse(input[i]));
    return result;
}

int main() {
    /*string input[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"};*/
    string input[9] = {
        "..4...63.",
        ".........",
        "5......9.",
        "...56....",
        "4.3.....1",
        "...7.....",
        "...5.....",
        ".........",
        "........."};
    vector<vector<char> > board = parse_input(input);
    Solution solution;
    cout << solution.isValidSudoku(board) << endl;
    return 0;
}
