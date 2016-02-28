/* - the problem can be solved by an approach similar to binary search
 *   let [start, end] be a range where the minimum lies in
 *   compare the middle number with the number at position end
 *
 *                    x x
 *               x x    |
 *             x        |
 *        x    |        |
 *        |    |        |
 *      start mid     end
 *
 *        x x  x  x         x  x  x
 *        |       |     x   |     |
 *        |       |   x     |     | 
 *      start    mid       mid   end
 *
 *    if the middle number is smaller than the number at position end, we know that the minimum
 *      number lies in range [start, mid]
 *    if the middle number is larger than the number at position end, we know that the minimum
 *      number lies in range [mid + 1, end]
 *    however, if the middle number is equal to the number at position end, we do not know
 *      which range the minimum number lies in; in this case, what we can do is to decrement
 *      the end by one
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
            else if (nums[mid] > nums[end]) start = mid + 1;
            else end--;
        }
        return nums[start];
    }
};

int main() {
    int a[] = { 3, 1, 2, 3, 3, 3, 3 };
    vector<int> nums(a, a + 7);
    Solution solution;
    cout << solution.findMin(nums) << endl;
    return 0;
}
