#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.size() == 0) return 0;
        int sum[grid.size()][grid[0].size()];
        sum[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < grid[0].size(); j++) sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                sum[i][j] = min(sum[i][j - 1], sum[i - 1][j]) + grid[i][j];
            }
        }
        return sum[grid.size() - 1][grid[0].size() - 1];   
    }
};

int main() {

    return 0;
}
