/* - the problem can be solved via approach similar to bucket sort: put th input numbers
 *   to their corresponding position of the input array, i.e. number i is put to index i of the
 *   array. next, visit the modified input array again to see which number is missing
 *   ex.
 *   iteration 0:
 *       0  1  2  3  4  ==> position
 *       2  5  3  0  1  ==> input array
 *       |---->|
 *             |->|
 *       |<-------|
 *   iteration 1:
 *       0  1  2  3  4  ==> position
 *       0  5  2  3  1  ==> input array
 *          |---------->|     (as number 5 is out of the array bound, the algorithm does nothing)
 *   iteration 2:
 *       0  1  2  3  4  ==> position
 *       0  5  2  3  1  ==> input array
 *          |<-------|
 *   final result:
 *       0  1  2  3  4  ==> position
 *       0  1  2  3  1  ==> input array
 *   traverse the input array again, and identifies number 4 as the missing number
 *   note that if all numbers of the array are not missing, output number 5 (size of the array)
 *   as the missing number
 * - the algorithm takes O(n) time and O(1) extra space
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i || nums[i] == nums.size())
                continue;
            int next = nums[i];
            nums[i] = nums.size();
            while (next < nums.size() && next != nums[next]) {
                int tmp = nums[next];
                nums[next] = next;
                next = tmp;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

int main() {
    int a[] = { 2, 5, 3, 0, 1 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.missingNumber(nums) << endl;
    return 0;
}
