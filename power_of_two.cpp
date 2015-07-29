/* - if the number is less than or equal to 0, immediately return false; otherwise,
 *   check if the binary representation of the number contains only one digit 1
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else return onlySingleOne(n);
    }
    bool onlySingleOne(int n) {
        bool readOne = false;
        while (n > 0) {
            if ((n & 1) == 1) {
                if (readOne) return false;
                else readOne = true;
            }
            n = n >> 1;
        }
        return readOne;
    }
};

int main() {
    Solution solution;
    cout << solution.isPowerOfTwo(0) << endl;
    cout << solution.isPowerOfTwo(2) << endl;
    cout << solution.isPowerOfTwo(4) << endl;
    cout << solution.isPowerOfTwo(8) << endl;
    cout << solution.isPowerOfTwo(15) << endl;
    return 0;
}
