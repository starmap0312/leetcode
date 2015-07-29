/* - recursive solution has many repeated computation of subproblems, use dynamic programming
 *   to speedup
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n + 1, 1);
        for (int i = 1; i <= n; i++)
            compute(i, table);
        return table[n];
    }
    void compute(int n, vector<int> &table) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += table[i] * table[n - i - 1];
        table[n] = sum;
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}
