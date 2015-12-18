/* - a naive approach based on recursion
 *   this approach takes too much time and does not pass the tests
 * - at first glance, the problem is hard to solve using dynamic programming
 *   to devise one, think of the choice of the last balloon to burst, instead of the first balloon
 *   to burst
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        maxSum = INT_MIN;
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++)
            indices.push_back(i);
        for (int i = 0; i < indices.size(); i++) {
            solve(nums, indices, i, 0);
        }
        return maxSum;
    }

    void solve(vector<int>& nums, vector<int> &indices, int index, int sum) {
        int ind = indices[index];
        int left, mid = nums[ind], right;
        if (index - 1 < 0) left = 1;
        else left = nums[indices[index - 1]];
        if (index + 1 >= indices.size()) right = 1;
        else right = nums[indices[index + 1]];
        sum += (left * mid * right);
        indices.erase(indices.begin() + index);
        if (indices.size() == 0) {
            if (sum > maxSum) maxSum = sum;
        }
        for (int i = 0; i < indices.size(); i++) {
            solve(nums, indices, i, sum);
        }
        indices.insert(indices.begin() + index, ind);
    }

private:
    int maxSum;
};

int main() {
    int a[] = { 3, 1, 5, 8 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.maxCoins(nums) << endl;
    return 0;
}
