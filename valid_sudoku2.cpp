#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (int k = 1; k <= 9; k++) {
                    board[i][j] = (char)(k + '0');
                    if (isSafe(board, i, j) && isValidSudoku(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char> > &board, int row, int column) {
        set<char> dict;
        for (int i = 0; i < 9; i++) {
            if (dict.count(board[i][column]) > 0) return false;
            if (board[i][column] >= '1' && board[i][column] <= '9')
                dict.insert(board[i][column]);
        }
        dict.clear();
        for (int j = 0; j < 9; j++) {
            if (dict.count(board[row][j]) > 0) return false;
            if (board[row][j] >= '1' && board[row][j] <= '9')
                dict.insert(board[row][j]);
        }
        dict.clear();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int x = (row / 3) * 3, y = (column / 3) * 3;
                if (dict.count(board[x + i][y + j]) > 0) return false;
                if (board[x + i][y + j] >= '1' && board[x + i][y + j] <= '9')
                    dict.insert(board[x + i][y + j]);
            }
        return true;
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
    string input[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"};
    /*string input[9] = {
        "..4...63.",
        ".........",
        "5......9.",
        "...56....",
        "4.3.....1",
        "...7.....",
        "...5.....",
        ".........",
        "........."};*/
    vector<vector<char> > board = parse_input(input);
    Solution solution;
    cout << solution.isValidSudoku(board) << endl;
    return 0;
}
