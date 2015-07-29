/* - the easy way is to convert the input number into a vector of digits, and check 
 *   if the vector is symmetric, but this requires extra space of the vector
 *   to avoid using extra space, we first compute the number of digits and then check
 *   each pair of digit is identical
 * - remember to handle the case where input number is negative
 *
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int digits = numDigits(x);
        for (int i = 0, j = digits - 1; i < j; i++, j--)
            if (ithDigit(i, x) != ithDigit(j, x)) return false;
        return true;
    }
    int numDigits(int x) {
        int result = 0;
        while (x > 0) {
            result++;
            x /= 10;
        }
        return result;
    }
    int ithDigit(int i, int x) {
        while (i > 0) {
            x /= 10;
            i--;
        }
        return x % 10;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(1) << endl;
    cout << solution.isPalindrome(10) << endl;
    cout << solution.isPalindrome(101) << endl;
    return 0;
}
