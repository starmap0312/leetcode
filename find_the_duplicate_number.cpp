/* - to find the duplicate number in range (1 ... n), we first let mid = (1 + n) / 2
 *   observe that the duplicate number must exist in either range (1 ... mid) or
 *   in range (mid + 1 ... n)
 *   by counting the total number in-between the two ranges, one can determine the duplicate 
 *   number exists in which range.
 *   then, recursively finding the duplicate number in the determined range
 * - the total time of the above approach is O(n log n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1, j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            int lower = 0, higher = 0;
            for (int k = 0; k < nums.size(); k++) {
                if (nums[k] >= i && nums[k] <= mid) lower++;
                else if (nums[k] > mid && nums[k] <= j) higher++;
            }
            if (lower > mid - i + 1) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};

int main() {
    int a[] = { 1, 4, 3, 2, 4 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.findDuplicate(nums) << endl;
    return 0;
}
