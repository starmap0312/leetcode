/* - the problem is related to buckect sort: if one can use extra space of O(n), then simply
 *   visit the input numbers and put into the buckets
 *   ex.
 *   after bucket sorting, we have:
 *   0 1 2 3 4 5 6
 *   1 2 x 4 x 6 x
 *   then the first missing positive is 3.
 * - as the problem has a constraint of using O(1) extra space, we need to swap numbers in place
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1 && nums[i] >= 1 && nums[i] < nums.size()) {
                if (nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
};

int main() {
    int a[] = { 3, 4, -1, 1 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}
