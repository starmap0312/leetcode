/* - observe that board[][] is an array of int and its initial values are either 0 or 1
 *   use a higher digit to record the updated values without chaning the first bit of 0 or 1
 *   i.e. traverse each cell of the array and compute the number of its neighbors
 *        compute and store the updated value to the 2nd bit of the int
 *        once all updated values are computed and stored, shift the int of each cell to the
 *        right by one so that each cell now stores the updated value
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        if (board.size() == 0) return;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                update(board, i, j);
            }
        }
        shift(board);
    }

    void shift(vector<vector<int> >& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] = (board[i][j] >> 1);
            }
        }
    }

    void update(vector<vector<int> >& board, int i, int j) {
        if (life(board, i, j) == 0) {
            if (numNeighbors(board, i, j) == 3)
                board[i][j] = (board[i][j] | 2);
        } else {
            if (numNeighbors(board, i, j) == 2 || numNeighbors(board, i, j) == 3)
                board[i][j] = (board[i][j] | 2);
        }
    }

    int numNeighbors(vector<vector<int> >& board, int i, int j) {
        int sum = 0;
        return life(board, i - 1, j - 1) + life(board, i - 1, j) + life(board, i - 1, j + 1) +
               life(board, i, j - 1) + life(board, i, j + 1) +
               life(board, i + 1, j - 1) + life(board, i + 1, j) + life(board, i + 1, j + 1);
    }

    int life(vector<vector<int> >& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return 0;
        return (board[i][j] & 1);
    }
};

int main() {
    int a1[] = { 1, 1 };
    int a2[] = { 1, 0 };
    vector<vector<int> > board;
    board.push_back(vector<int>(a1, a1 + 2));
    board.push_back(vector<int>(a2, a2 + 2));
    Solution solution;
    solution.gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
