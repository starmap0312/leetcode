/* - observe the periodicity
 *   ex.               addDigits(num)   addDigits(num)   num % 9
 *       1  10  19 ==> (1 + 9) = 10 ==> (1 + 0) = 1  ... 1 + 9x
 *       2  11  20 ==> (2 + 0) = 2                   ... 2 + 9x
 *       3  12  21 ==> (2 + 1) = 3                   ... 3 + 9x
 *       4  13  22 ==> (2 + 2) = 4                   ... 4 + 9x
 *       5  14  23 ==> (2 + 3) = 5                   ... 5 + 9x
 *       6  15  24 ==> (2 + 4) = 6                   ... 6 + 9x
 *       7  16  25 ==> (2 + 5) = 7                   ... 7 + 9x
 *       8  17  26 ==> (2 + 6) = 8                   ... 8 + 9x
 *       9  18  27 ==> (2 + 7) = 9                   ... 9 + 9x
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

int main() {
    Solution solution;
    cout << solution.addDigits(38) << endl;
    return 0;
}
