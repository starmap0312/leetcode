/* - dynamic programming solution 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int m) {
        vector<int> ans(m + 1);
        ans[0] = 1;
        for (int n = 1; n <= m; n++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {               // compute the answer of size n via smaller sizes 
                sum += ans[i] * ans[n - i - 1];
            }
            ans[n] = sum;
        }
        return ans[m];
    }

    int recursive(int n) {
        if (n == 0) return 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += recursive(i) * recursive(n - i - 1); // compute the answer of size n via recursion
        }
        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
    cout << solution.recursive(3) << endl;
    return 0;
}
