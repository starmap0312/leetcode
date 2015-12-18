/* - try to improve the time by modifying the method of findConnected() using an approach
 *   similar to the solution of the problem "number of islands"
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
               board[i][j] = 'X';
       for (set<pair<int, int> >::iterator itr = visited.begin(); itr != visited.end(); itr++)
           board[(*itr).first][(*itr).second] = 'O';
    }

    void findConnected(vector<vector<char> >& board, set<pair<int, int> >& visited, int i, int j) {
        set<pair<int, int> > unvisited;
        unvisited.insert(make_pair(i, j));
        while (!unvisited.empty()) {
            pair<int, int> p = *unvisited.begin();
            unvisited.erase(unvisited.begin());
            board[i][j] = 'X';
            visited.insert(p);
            pair<int, int> p1 = make_pair(p.first - 1, p.second);
            if (isValid(board, p1) && visited.find(p1) == visited.end()) unvisited.insert(p1);
            pair<int, int> p2 = make_pair(p.first + 1, p.second);
            if (isValid(board, p2) && visited.find(p2) == visited.end()) unvisited.insert(p2);
            pair<int, int> p3 = make_pair(p.first, p.second - 1);
            if (isValid(board, p3) && visited.find(p3) == visited.end()) unvisited.insert(p3);
            pair<int, int> p4 = make_pair(p.first, p.second + 1);
            if (isValid(board, p4) && visited.find(p4) == visited.end()) unvisited.insert(p4);
        }
    }

    bool isValid(vector<vector<char> >& board, pair<int, int> &p) {
        if (p.first >= 0 && p.first < board.size() &&
            p.second >= 0 && p.second < board[0].size() && board[p.first][p.second] == 'O')
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
