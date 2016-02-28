/* - at first glance, it seems that the problem has a trivial lowerbound, which is O(n), 
 *   one may think that to find the peak element, the numbers must be visited at least once
 *   but this is not correct
 * - the problem can be solved in O(log n) time using binary search:
 *   i.e. by checking the middle number with its preceding number
 *        one can determine that at least one half of the numbers that contains the peak element
 *   ex.                 
 *                       |
 *                   x   |
 *                       |      x
 *                x      x
 *        x              |  x         x
 *    -infinity          |        -infinity
 *                       
 *    1) case 1:                x
 *                              |
 *                       x      |
 *                       |      |
 *                    mid - 1  mid       end
 *                              ^
 *                            start
 *
 *       case 2:         x      
 *                       |      
 *                       |      x
 *                       |      |
 *          start     mid - 1  mid
 *                              ^
 *                             end
 *
 *    2) ensure the correctness of the boundary cases where there are 1, 2, or 3 numbers
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int start = 0, end = nums.size();
        while (start < end - 1) { // if start == end - 1, return the only one candidate
            int mid = (start + end) / 2;
            if (nums[mid - 1] < nums[mid])
                start = mid;
            else
                end = mid;
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
