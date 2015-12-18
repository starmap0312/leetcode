/* - use dynamic programming to solve the problem:
 *   ex. nums[0...n - 1]  ==> input array
 *       nums[0...n + 1]  ==> add two ballons of value 1 to the two ends
 *   the answer of the problem is ans[0][n + 1]
 * - the recursion:
 *   let ans[i][j] denote the maximum sum that can be obtained by bursting balloons without
 *   the two boundary ballons, i.e. bursting ballons of nums[i + 1...j - 1] arbitrarily
 *   observe that ans[i][j] can be computed recursively as follows:
 *   ans[i][j] = max(ans[i][k] + ans[k][j] + nums[i] * nums[k] * nums[j]) for all i < k < j,
 *   where nums[k] is the chosen ballon to be burst lastly
 * - the order of computation:
 *   to compute the answer of all i, j where j - i = l, the answers of all i, j 
 *   where j - i = l' for all l' < l must already be computed
 * - boundary case: ans[i][j] = 0 for j - i = 1
 * - the total time of the above approach is O(n ^ 3)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1), nums.insert(nums.end(), 1);
        vector<vector<int> > ans(nums.size(), vector<int>(nums.size(), 0));
        for (int l = 2; l < nums.size(); l++) {
            for (int i = 0; i < nums.size() - l; i++) {
                int j = i + l;
                int maxsum = 0;
                for (int k = i + 1; k <= j - 1; k++) {
                    int sum = ans[i][k] + ans[k][j] + nums[i] * nums[k] * nums[j];
                    if (sum > maxsum) maxsum = sum;
                }
                ans[i][j] = maxsum;
            }
        }
        return ans[0][nums.size() - 1];
    }
};

int main() {
    int a[] = { 3, 1, 5, 8 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.maxCoins(nums) << endl;
    return 0;
}
