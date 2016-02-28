/* - the problem can be solved by summing up all the numbers and substract with (0 + 1 + ... + n)
 *   however, this solution has its limit as it does not handle the integer overflow
 * - an alternative approach is to use bucket sort to identify the missing number
 * - both approaches can be done in O(n) time and O(1) extra space 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return ((nums.size() * (nums.size() + 1) / 2) - sum);
    }
};

int main() {
    int a[] = { 0, 1, 3 };
    vector<int> nums(a, a + 3);
    Solution solution;
    cout << solution.missingNumber(nums) << endl;
    return 0;
}
