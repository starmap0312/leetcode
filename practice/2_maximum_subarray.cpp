/* - compute the prefix sums on the fly, during a scan of the input numbers
 *   to find the maximum subarray ending at position i, it suffices to find the minimum prefix sum before position i
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
