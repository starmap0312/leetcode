/* - check all the border 'O' cells, extend and find all their neighboring 'O' cells
 *   store all the found 'O' in a set; all the cells not in the set must be set to 'X'
 * - queue<int> q; ==> q.push(3) will push element 3 to the back of the queue
 *                     q.pop() will pop the front element of the queue
 *                     while (!q.empty()) {
 *                         cout << q.front() << endl; q.pop();
 *                     } // traverse the queue in FIFO order
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
       if (board.size() == 0) return;
       set<pair<int, int> > visited;
       for (int i = 0; i < board.size(); i++) {
           if (board[i][0] == 'O')
               findConnected(board, visited, i, 0);
           if (board[i][board[0].size() - 1] == 'O')
               findConnected(board, visited, i, board[0].size() - 1);
       }
       for (int j = 1; j < board[0].size() - 1; j++) {
           if (board[0][j] == 'O')
               findConnected(board, visited, 0, j);
           if (board[board.size() - 1][j] == 'O')
               findConnected(board, visited, board.size() - 1, j);
       }
       for (int i = 0; i < board.size(); i++)
           for (int j = 0; j < board[i].size(); j++)
               if (visited.find(make_pair(i, j)) == visited.end())
                   board[i][j] = 'X';
    }

    void findConnected(vector<vector<char> >& board, set<pair<int, int> >& visited, int i, int j) {
        visited.insert(make_pair(i, j));
        queue<pair<int, int> > unvisited;
        unvisited.push(make_pair(i, j));
        while (!unvisited.empty()) {
            pair<int, int> p = unvisited.front();
            unvisited.pop();
            vector<pair<int, int> > nbr;
            nbr.push_back(make_pair(p.first - 1, p.second));
            nbr.push_back(make_pair(p.first + 1, p.second));
            nbr.push_back(make_pair(p.first, p.second - 1));
            nbr.push_back(make_pair(p.first, p.second + 1));
            for (int i = 0; i < nbr.size(); i++) {
                if (isValid(board, nbr[i].first, nbr[i].second) && 
                    visited.find(nbr[i]) == visited.end()) {
                    visited.insert(nbr[i]);
                    unvisited.push(nbr[i]);
                }
            }
        }
    }

    bool isValid(vector<vector<char> >& board, int i, int j) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O')
            return true;
        return false;
    }
};

int main() {
    vector<vector<char> > board;
    char a1[] = { 'X', 'X', 'X', 'X' };
    char a2[] = { 'X', 'O', 'O', 'X' };
    char a3[] = { 'X', 'X', 'O', 'X' };
    char a4[] = { 'X', 'O', 'X', 'X' };
    board.push_back(vector<char>(a1, a1 + 4));
    board.push_back(vector<char>(a2, a2 + 4));
    board.push_back(vector<char>(a3, a3 + 4));
    board.push_back(vector<char>(a4, a4 + 4));
    Solution solution;
    solution.solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
