/* - the problem can be solved by computing the prefix sums during a scan of the input numbers
 *   using the prefix sums, one can identify the maximum subarrays ending at each position
 *   for example, the maximum subarray ending at position i has a sum equal to the prefix sum
 *   of that position minus the lowest prefix sum before that position
 *   therefore, while computing the prefix sums, we also keep track of the lowest prefix sum
 *   computed so far, and update the sum of the maximum subarray on the fly
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prefixSum = 0, minPrefixSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int sum = prefixSum - minPrefixSum;
            if (prefixSum < minPrefixSum) minPrefixSum = prefixSum;
            if (sum > maxSum) maxSum = sum;
        }
        return maxSum;
    }
};

int main() {
    int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    vector<int> nums(a, a + 9);
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
