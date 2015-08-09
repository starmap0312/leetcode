/* - consider the following cases:
 *                        0  1  2  3  4
 *   strictly increasing: 1, 3, 5, 8, 9 ==> ans = 4
 *   strictly decreasing: 9, 8, 5, 3, 1 ==> ans = 0
 * - imagine that nums[-1] == -infinity and nums[nums.size()] == -infinity
 *   as long as the first two elements are increasing and the last two elements are decreasing
 *   you can always find the answer (a peak) in-between
 *   therefore, there exists a worst-case O(log n)-time algorithm described as follows
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int middle = (start + end) / 2;
            if (nums[middle] < nums[middle + 1])
                start = middle + 1;
            else
                end = middle;
        }
        return start;
    }
};

int main() {
    int a[] = { 1, 2, 3, 1 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}
