/*  beg    mid      end
 *  [  ............ )
 *         [        )
 *         [ )
 * - consider the boundary cases where the target is strictly smaller than all the input numbers or
 *   the target is strictly larger than all the input numbers
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size();
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) end = mid;
            else beg = mid + 1;
        }
        return beg;
    }
};

int main() {
    int a[] = { 1, 3, 5, 6 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.searchInsert(nums, 5) << endl;
    return 0;
}
