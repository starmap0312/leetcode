/* - try all possibilities using recursion, but the algorithm takes long time
 *   use dynamic programming instead
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        solve(dungeon, 0, 0, 0, INT_MAX);
        return (maximum < 0? maximum * -1: 0);
    }
    void solve(vector<vector<int> >& dungeon, int i, int j, int sum, int minimum) {
        if (i >= dungeon.size() || j >= dungeon[0].size()) return;
        sum += dungeon[i][j];
        minimum = min(minimum, sum);
        if (minimum < maximum) return;
        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            if (minimum > maximum) maximum = minimum;
        }
        solve(dungeon, i + 1, j, sum, minimum);
        solve(dungeon, i, j + 1, sum, minimum);
    }
    Solution() : maximum(INT_MIN) { }
private:
    int maximum;
};

int main() {
    int a[3][3] = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(&a[0][0], &a[0][3]));
    dungeon.push_back(vector<int>(&a[1][0], &a[1][3]));
    dungeon.push_back(vector<int>(&a[2][0], &a[2][3]));
    Solution solution;
    cout << solution.calculateMinimumHP(dungeon) << endl;
    return 0;
}
