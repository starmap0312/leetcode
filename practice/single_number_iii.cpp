/*       010 (2)
 *       011 (3)
 *       010 (2)
 *   XOR 100 (4)
 *      ----
 *       111 == (3 XOR 4)
 *   (010, 010, 100)
 *   (011)
 * - to summarize, the problem can be solved by observing that one can identify one bit that
 *   is different in the two single numbers, and divide the input numbers into two groups based
 *   on the difference of that bit, and identify the two single numbers, one from each group
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num1 = 0, num2 = 0, xorNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorNum ^= nums[i];
        }
        int nonZeroBit = 1;
        for (int i = 0; i < 32 && ((xorNum & nonZeroBit) == 0); i++) {
            nonZeroBit <<= 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & nonZeroBit) == 0) num1 ^= nums[i];
            else num2 ^= nums[i];
        }
        vector<int> result;
        result.push_back(num1), result.push_back(num2);
        return result;
    }
};

int main() {
    int a[] = { 2, 3, 2, 4 };
    vector<int> nums(a, a + 4);
    Solution solution;
    vector<int> rc = solution.singleNumber(nums);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
