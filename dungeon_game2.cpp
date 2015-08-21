/* - a dynamic programming approach: the idea works only if you think of constructing the
 *   table in the reverse order (from bottom-right corner to upper-left corner)
 * - knowing the answers of ans[i + 1][j] and ans[i][j + 1] will easily give you the answer of
 *   ans[i][j]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        vector<vector<int> > ans(dungeon.size(), vector<int>(dungeon[0].size()));
        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = dungeon[i].size() - 1; j >= 0; j--) {
                int initial = max(-dungeon[i][j] + 1, 1);
                int remaining = initial + dungeon[i][j];
                if (i == dungeon.size() - 1 && j == dungeon[i].size() - 1) {
                    ans[i][j] = initial;
                } else if (i == dungeon.size() - 1) {
                    if (remaining >= ans[i][j + 1]) ans[i][j] = initial;
                    else ans[i][j] = initial + (ans[i][j + 1] - remaining);
                } else if (j == dungeon[i].size() - 1) {
                    if (remaining >= ans[i + 1][j]) ans[i][j] = initial;
                    else ans[i][j] = initial + (ans[i + 1][j] - remaining);
                } else {
                    if (remaining >= min(ans[i + 1][j], ans[i][j + 1])) ans[i][j] = initial;
                    else ans[i][j] = initial + (min(ans[i + 1][j], ans[i][j + 1]) - remaining);
                }
            }
        }
        return ans[0][0]; 
    }
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
