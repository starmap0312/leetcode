/* - use bit operation: (n & 1) == (n % 2), (n >> 1) == (n / 2)
 */
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int numBits = 0;
        while (n > 0) {
            result = (result << 1) + (n & 1);
            n = (n >> 1);
            numBits++;
        }
        for (int i = 0; i < 32 - numBits; i++)
            result = (result << 1);
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseBits(43261596) << endl;
    return 0;
}
