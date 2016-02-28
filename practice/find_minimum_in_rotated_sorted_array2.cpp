/* - the problem can be solved by an approach similar to binary search
 *   let [start, end] be a range where the minimum lies in
 *   compare the middle number with the number at position end
 *
 *                   x
 *               x   |
 *             x     |
 *        x    |     |
 *        |    |     |
 *      start mid   end
 *
 *               x
 *           x   |
 *        x      |
 *        |      |            x
 *        |      |          x |
 *        |      |      x     |
 *        |      |      |     |
 *      start   mid    mid   end
 *
 *    if the middle number is smaller than the number at position end, we know that the minimum
 *      number lies in range [start, mid]
 *    otherwise, the minimum number lies in range [mid + 1, end]
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
            int mid = (start + end) / 2;
            if (nums[mid] < nums[end]) end = mid; 
            else start = mid + 1;
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
