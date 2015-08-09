/* - the naive sequential search algorithm runs in worst-case O(n) time
 *   note that the following algorithm works correctly for special cases where the input numbers
 *   are strictly increasing or strictly descreaing
 * - there exists a worst-case O(log n) time algorithm by dividing the list into two halves and
 *   always look for the one half that contains a peak element
 * - a number sequence contains a peak element if its first two elements are increasing and
 *   its last two elements are decreasing
 * - imagine that nums[-1] == -infinity and nums[nums.size()] == -infinity, which means that
 *   there exists a peak element in-between
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i;
        for (i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return i;
    }
};

int main() {
    int a[] = { 1, 2, 3, 1 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}
