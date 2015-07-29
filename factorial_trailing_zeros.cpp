#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int factor = 1, count = 0, m = n, power = 1;
        while (m / 5 > 0) {
            factor = factor * 5;
            int quotient = n / factor, remainder = n % factor;
            count += ((quotient / 5) * 4 + (quotient % 5)) * power;
            m = m / 5;
            power++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.trailingZeroes(13) << endl;
    cout << solution.trailingZeroes(51) << endl;
    return 0;
}
