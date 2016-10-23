/* - the problem can be solved via dynamic programming:
 *   let maxSum[i] be the sum of maximum subarray ending at position i
 *   note that: maxSum[i + 1] = max(maxSum[i] + nums[i + 1], 0)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxSum = 0, result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxSum = maxSum + nums[i];
            if (result < maxSum) result = maxSum;
            if (maxSum < 0) maxSum = 0;
        }
        return result;
    }
};

int main() {
    int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    vector<int> nums(a, a + 9);
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
