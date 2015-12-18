/* - int A[10] = { 0 }; ==> initialize an array to all values equal to 0
 * - int a = 2; ==> a << 2 shifts all the bits of a to the left by 2 (0010 ==> 1000)
 * - the problem can be solved by bit operations: note that C++ int type has 32 bits
 *   one can compute that single number bit by bit as follows:
 *   since every number appears 3 times except for the single, we know that "the i-th bit of 
 *   the single number" is "the amount of 1's of all numbers' i-th bits mod 3"
 *   therefore, traverse the input array once, store compute the amount of 1's for each each
 *   bit in an int[32] array
 * - the time required is O(n * 32) and the space required is O(32)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++)
                if ((nums[i] >> j) & 1) count[j]++;
        }
        int result = 0;
        for (int i = 0; i < 32; i++) {
            count[i] = count[i] % 3;
            result += (count[i] << i);
        }
        return result;
    }
};

int main() {
    int a[] = { 3, 2, 2, 3, 5, 2, 3 };
    vector<int> nums(a, a + 7);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
