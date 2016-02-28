/* - the problem can be solved by an approach similar to binary search
 *   let [start, end] be a range where the minimum lies in
 *   first, check if the numbers in [start, end] is increasing
 *     if so, the minimum number is at position start
 *
 *                   x
 *               x   |
 *             x     |
 *        x          |
 *        |          |
 *      start       end
 *
 *     if not, consider the middle number, i.e. number at position (start + end) / 2
 *
 *                
 *               x
 *           x   |
 *        x      |
 *        |      |            x
 *        |      |          x |
 *        |      |      x     |
 *      start   mid          end
 *
 *       if the middle number is no smaller than the number at position start, we know
 *       that the minimum number lies in range [mid + 1, end]
 *       otherwise, the minimum number lies in range [start, mid]
 * - in fact, if we always compare the middle number with the number at position end, we can
 *   omit the checking of increasing numbers
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] <= nums[end]) return nums[start];
            int mid = (start + end) / 2;
            if (nums[start] <= nums[mid]) start = mid + 1; 
            else end = mid;
        }
        return nums[start];
    }
};

int main() {
    int a[] = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums(a, a + 7);
    Solution solution;
    cout << solution.findMin(nums) << endl;
    return 0;
}
