/* - use factoring and dynamic programming to speedup the computation
 *   ex. 2 ^ 9 == 2 ^ 1001 = (2 ^ 8) * 1 + (2 ^ 4) * 0 + (2 ^ 2) * 0 + (2 ^ 1) * 1
 *       use dynamic programming to  2 ^ 8, 2 ^ 4, 2 ^ 2, 2 ^ 1
 * - need to handle input where n is negative
 */
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool positive = (n > 0? true: false);
        n = (n < 0? n * -1: n);
        double sum = 1.0;
        while (n > 0) {
            if ((n & 1) == 1) sum = sum * x;
            n = n >> 1;
            x = x * x; 
        }
        return (positive? sum: 1 / sum);
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(8.88023, 3) << endl;
    return 0;
}
