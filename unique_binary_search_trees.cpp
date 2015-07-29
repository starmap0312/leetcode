/* - recursive solution has many repeated computation of subproblems, use dynamic programming
 *   to speedup
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += numTrees(i) * numTrees(n - i - 1);
        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}
