/* - dynamic programming solution 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1, 1);
        for (int i = 1; i <= n; i++)
            compute(i, ans);
        return ans[n];
    }
    void compute(int n, vector<int> &ans) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += ans[i] * ans[n - i - 1];
        ans[n] = sum;
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}
