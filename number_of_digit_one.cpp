/* - the problem requires observing the pattern of real cases
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int m = n, numDigits = 0, count = 0;
        while (m > 0) {
            numDigits++;
            int digit = m % 10;
            int lhs = getLHS(n, numDigits), rhs = getRHS(n, numDigits);
            if (digit == 0) count += (lhs * powerOfTen(numDigits));
            else if (digit == 1) count += (lhs * powerOfTen(numDigits)) + (rhs + 1);
            else count += (lhs + 1) * powerOfTen(numDigits);
            m = m / 10;
        }
        return count;
    }
    int getLHS(int n, int pos) {
        while (pos > 0) {
            n = n / 10;
            pos--;
        }
        return n;
    }
    int getRHS(int n, int pos) {
        return (n % powerOfTen(pos));
    }
    int powerOfTen(int numDigits) {
        int result = 1;
        while (numDigits > 1) {
            result = result * 10;
            numDigits--;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.countDigitOne(13) << endl;
    return 0;
}
