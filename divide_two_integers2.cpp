/* - ex. 33 / 3 == 1 * (3 * 8) + 0 * (3 * 4) + 1 * (3 * 2) + 1 * (3 * 1)
 *              == 1 * (   24) + 0 * (   12) + 1 * (    6) + 1 * (    3)
 *       first, find the most significant factor: 8 and subtract 33 - 24 == 9
 *       next,  find the next factor: 6 and subtract 9 - 6 == 3
 *       finally, find the next factor: 3 and subtract 3 - 3 == 0
 *       return the answer of (8 + 2 + 1) == 11
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = ((dividend >= 0 && divisor >= 0) || 
            (dividend < 0 && divisor < 0) ? true: false);
        if (dividend == divisor) return (positive? 1: -1);
        if (divisor == INT_MIN) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else return (dividend * -1);
        }
        long x = (dividend > 0? dividend: (long) dividend * -1);
        long y = (divisor > 0? divisor: (long) divisor * -1);
        long quotient = 0;
        while (x >= y) {
            maxPower(x, y, x, quotient);
        }
        if (positive)
            return (quotient > INT_MAX? INT_MAX: quotient);
        else
            return (quotient < INT_MIN? INT_MAX: quotient * -1);
    }
    void maxPower(long x, long y, long &dividend, long &quotient) {
        if (x < y) return;
        long sum = y, power = 1;
        while (sum <= x - sum) {
            sum = sum + sum;
            power = power + power;
        }
        dividend -= sum;
        quotient += power;
    }
};

int main() {
    Solution solution;
    cout << solution.divide(-2147483648, 2) << endl;
    cout << solution.divide(88, 3) << endl;
    cout << solution.divide(1, -1) << endl;
    cout << solution.divide(INT_MAX, 1) << endl;
    return 0;
}
