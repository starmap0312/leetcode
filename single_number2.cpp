/* - C++ bit operations ==> AND(a & b), OR(a | b), XOR(a ^ b), NOT(~a) 
 * - the problem can be solved by bit operations
 *   note that odd number of 1's bits results in 1 when XORing them ==> 1 XOR 0 XOR 1 XOR 1 == 1
 *                                                                      1 XOR 0 XOR 1 XOR 0 == 0
 *   so in this problem, by XORing all the inut numbers we get all the 1's bits of the 
 *   single number
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};

int main() {
    int a[4] = { 1, 2, 4, 3 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
