/* - the problem can be easily solved in linear time
 *   to solve the problem in-place, use bit operations:
 *   i.e. use the 2nd bit to store the value of the next state and after all the values of
 *        the next state are computed, shift all the values to the right by one bit
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int num = numNeighbors(board, i, j);
                if (isAlive(board, i, j) && (num == 2 || num == 3))
                    board[i][j] |= 2;
                if (!isAlive(board, i, j) && num == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                board[i][j] >>= 1;
    }

    bool isAlive(vector<vector<int> >& board, int row, int column) {
        return ((board[row][column] & 1) == 1);
    }

    int numNeighbors(vector<vector<int> >& board, int row, int column) {
        int count = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            if (i < 0 || i >= board.size()) continue;
            for (int j = column - 1; j <= column + 1; j++) {
                if (j < 0 || j >= board[0].size()) continue;
                if (i == row && j == column) continue;
                count += (board[i][j] & 1);
            }
        }
        return count;
    }
};

int main() {
    int a[] = { 1, 1 };
    vector<vector<int> > board;
    board.push_back(vector<int>(a, a + 2));
    Solution solution;
    solution.gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
