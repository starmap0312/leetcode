/* - the problem is solved by observing that:
 *   when m <= 2^k - 1 && 2^k <= n, the answer is 0
 *   otherwise, solve the problem by brute force (ANDing every number between m and n)
 */
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = mostSignificant(m);
        int a = pow(2, k);
        if (m <= a - 1 && a <= n) return 0;
        if (k < 30 && (int) pow(2, k + 1) <= n) return 0;
        return solve(m, n);
    }
    int mostSignificant(int m) {
       int powerOfTwo = 1, i = 30;
       for (; i >= 0; i--)
           if ((m & (powerOfTwo << i)) > 0)
               break;
       return i;
    }
    int solve(int m, int n) {
        if (m == INT_MAX) return m;
        for (int i = m + 1; i < n; i++) {
            m = m & i;
        }
        return m & n;        
    }
};

int main() {
    Solution solution;
    cout << solution.rangeBitwiseAnd(5, 7) << endl;
    cout << solution.rangeBitwiseAnd(2147483646, 2147483647) << endl;
    cout << solution.rangeBitwiseAnd(2147483647, 2147483647) << endl;
    return 0;
}
