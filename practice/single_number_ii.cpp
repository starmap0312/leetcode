/*     4  (100)
 *     3  (011)
 *     4  (100)
 *   + 4  (100)
 *   ----------
 *        (311)
 * - the idea is consider each of the 32 bits of an integer  
 *   adding up each of the bits of all input numbers separately
 *   if the i-th bit is not divisible by 3, then the single number should contribute a 1's to the
 *   i-th bit
 * - the algorithm uses O(n) time and O(1) extra space
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) != 0) bits[j]++;
            }
        }
        int result = 0;
        for (int j = 0; j < 32; j++) {
            if (bits[j] % 3 == 1) result += (1 << j);
        }
        return result;
    }
};

int main() {
    int a[] = { 1, 3, 1, 2, 1, 3, 2, 3, 4, 2 };
    vector<int> nums(a, a + 10);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
