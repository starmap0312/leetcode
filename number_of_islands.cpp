/* - scan the cells from left to right, top to bottom
 * - whenever identifies a '1' cell, mark it as '0' and start the extension of the island
 *   the extension checks the four neighbors of a cell and add the neighbor cell to a set
 *   if the cell is a '1' cell and not in the set (note that a '1' cell is marked as '0' when
 *   the extension is done for the cell)
 * - one cannot use queue to maintain the set, as there is no find() member function of the
 *   queue data structure (therefore, one cannot check if a value is in the set or not)
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0') continue;
                else count++;
                set<pair<int, int> > extension;
                extension.insert(make_pair(i, j));
                while (!extension.empty()) {
                    pair<int, int> p = *extension.begin();
                    extension.erase(extension.begin());
                    grid[p.first][p.second] = '0';
                    if (isValid(grid, p.first - 1, p.second)) {
                        pair<int, int> q = make_pair(p.first - 1, p.second);
                        if (extension.find(q) == extension.end())
                            extension.insert(q);
                    }
                    if (isValid(grid, p.first + 1, p.second)) {
                        pair<int, int> q = make_pair(p.first + 1, p.second);
                        if (extension.find(q) == extension.end())
                            extension.insert(q);
                    }
                    if (isValid(grid, p.first, p.second - 1)) {
                        pair<int, int> q = make_pair(p.first, p.second - 1);
                        if (extension.find(q) == extension.end())
                            extension.insert(q);
                    }
                    if (isValid(grid, p.first, p.second + 1)) {
                        pair<int, int> q = make_pair(p.first, p.second + 1);
                        if (extension.find(q) == extension.end())
                            extension.insert(q);
                    }
                }
            }
        }
        return count;
    }

    bool isValid(vector<vector<char> >& grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1')
            return true;
        return false;
    }
};

int main() {
    char a1[] = { '1', '1', '0', '0', '0' };
    char a2[] = { '1', '1', '0', '0', '0' };
    char a3[] = { '0', '0', '1', '0', '0' };
    char a4[] = { '0', '0', '0', '1', '1' };
    vector<vector<char> > grid;
    grid.push_back(vector<char>(a1, a1 + 5));
    grid.push_back(vector<char>(a2, a2 + 5));
    grid.push_back(vector<char>(a3, a3 + 5));
    grid.push_back(vector<char>(a4, a4 + 5));
    Solution solution;
    cout << solution.numIslands(grid) << endl;
    return 0;
}
