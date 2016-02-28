/* 010
 * 010
 * 111
 * 011
 * 011
 * (0 ^ 0) == 0
 * (0 ^ 1) == 1
 * (1 ^ 0) == 1
 * (1 ^ 1) == 0
 * observe that:
 *   XORing an odd number of 1's gives you 1
 *   XORing a even number of 1's gives you 0
 * therefore, XORing all the input numbers gives you the single number
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main() {
    int a[] = { 2, 2, 7, 3, 3 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
