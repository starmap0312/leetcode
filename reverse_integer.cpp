/* - make sure to check if the reversed number exceeds INT_MAX, if so, return 0;
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        int reversed = 0;
        while (num != 0) {
            if ((INT_MAX - num % 10) / 10 < reversed) return 0;
            reversed = 10 * reversed + num % 10;
            num = num / 10;
        }
        return (x >= 0? reversed: reversed * -1);
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(123) << endl;
    cout << solution.reverse(-123) << endl;
    return 0;
}
