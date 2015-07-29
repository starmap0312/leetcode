/* - the problem is solved by observing that:
 *   remainder        quotient ... next remainder
 *   1, 1 * 10 / 7 == 1 ... 3
 *   3, 3 * 10 / 7 == 4 ... 2
 *   2, 2 * 10 / 7 == 2 ... 6
 *   6, 6 * 10 / 7 == 8 ... 4
 *   4, 4 * 10 / 7 == 5 ... 5
 *   5, 5 * 10 / 7 == 7 ... 1 (found recurring remainder)
 *   Ans = 1 / 7 = 0.(142857)
 * - the program needs to handle negative input numbers and integer overflow
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        bool negative = (true? (n > 0 && d < 0) || (n < 0 && d > 0): false);
        n = (n < 0? n * -1: n);
        d = (d < 0? d * -1: d);
        vector<int> quotients, remainders;
        long quotient, remainder = n % d;
        int start = -1, end = -1;
        remainders.push_back(remainder);
        while (remainder != 0) {
            quotient = (remainder * 10) / d;
            remainder = (remainder * 10) % d;
            quotients.push_back(quotient);
            vector<int>::iterator itr = find(remainders.begin(), remainders.end(), remainder);
            if (itr == remainders.end()) {
                remainders.push_back(remainder);
            } else {
                start = itr - remainders.begin();
                end = remainders.end() - remainders.begin();
                break;
            }
        }
        string result = (negative? "-": "") + to_string(n / d) + 
            (quotients.size() > 0? ".": "");
        for (int i = 0; i < quotients.size(); i++) {
            if (i == start) result += "(";
            result += to_string(quotients[i]);
        }
        if (end != -1) result += ")";
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.fractionToDecimal(1, 7) << endl;
    return 0;
}
