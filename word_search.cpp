/* - use recursion, the algorithm keeps a list of chosen positions and uses the list to verify
 *   if the next choice can be made
 * - the time may be improved by duplicate the board and uses '#' symbol to mark the chocies
 *   the time for verification can be reduced
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                vector<pair<int, int> > solution;
                if (search(board, word, make_pair(i, j), solution)) return true;
            }
        return false;
    }
    bool search(vector<vector<char> > &board, string &word,
        pair<int, int> pos, vector<pair<int, int> > &solution) {
        if (!isValid(board, solution, pos)) return false;
        if (board[pos.first][pos.second] != word[solution.size()]) return false;
        solution.push_back(pos);
        if (solution.size() == word.size()) return true;
        // choice 1: up
        if (search(board, word, make_pair(pos.first - 1, pos.second), solution)) return true;
        // choice 2: right
        if (search(board, word, make_pair(pos.first, pos.second + 1), solution)) return true;
        // choice 3: down
        if (search(board, word, make_pair(pos.first + 1, pos.second), solution)) return true;
        // choice 4: left
        if (search(board, word, make_pair(pos.first, pos.second - 1), solution)) return true;
        solution.pop_back();
        return false;
    }
    bool isValid(vector<vector<char> > &board, vector<pair<int, int> > &solution, 
        pair<int, int> &pos) {
        if (pos.first < 0 || pos.second < 0 || pos.first >= board.size() || 
            pos.second >= board[0].size())
            return false;
        for (int i = 0; i < solution.size(); i++)
            if (solution[i].first == pos.first && solution[i].second == pos.second)
                return false;
        return true;
    }
};

int main() {
    char a[3][4] = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
        };
    vector<vector<char> > board;
    board.push_back(vector<char>(&a[0][0], &a[0][4]));
    board.push_back(vector<char>(&a[1][0], &a[1][4]));
    board.push_back(vector<char>(&a[2][0], &a[2][4]));
    Solution solution;
    cout << solution.exist(board, "ABCCED") << endl;
    return 0;
}
