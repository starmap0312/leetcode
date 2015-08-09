#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = ((dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0)? true: false);
        long x = (dividend > 0? dividend: (long) dividend * -1);
        long y = (divisor > 0? divisor: (long) divisor * -1);
        if (x == y) return (negative? 1: -1);
        if (y == 1) {
            long rc = (negative? x * -1: x);
            if (rc > INT_MAX) return INT_MAX;
            else return rc;
        }
        long quotient = 0;
        while (x > 0) {
            x -= y;
            if (x < 0) break;
            quotient++;
        }
        long rc = (negative? quotient * -1: quotient);
        if (rc > INT_MAX) return INT_MAX;
        else return rc;
    }
};

int main() {
    Solution solution;
    cout << solution.divide(45, 3) << endl;
    cout << solution.divide(88, 3) << endl;
    cout << solution.divide(1, -1) << endl;
    cout << solution.divide(INT_MAX, 1) << endl;
    cout << solution.divide(2147483647, 2) << endl;
    return 0;
}
