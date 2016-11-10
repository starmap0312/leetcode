/* - 
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rc = 0;
        vector<vector<bool> > visited;
        for (int i = 0; i < grid.size(); i++) {
            visited.push_back(vector<bool>(grid[i].size(), false));
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    rc++;
                    DFS(grid, visited, i, j);
                }
            }
        }
        return rc;
    }

    void DFS(vector<vector<char> >& grid, vector<vector<bool> > &visited, int i, int j) {
        // base step
        if (visited[i][j] == true || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true; // mark as visited
        // inductive step
        if (i - 1 >= 0) {
            DFS(grid, visited, i - 1, j);
        }
        if (i + 1 < grid.size()) {
            DFS(grid, visited, i + 1, j);
        }
        if (j - 1 >= 0) {
            DFS(grid, visited, i, j - 1);
        }
        if (j + 1 < grid[i].size()) {
            DFS(grid, visited, i, j + 1);
        }
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
