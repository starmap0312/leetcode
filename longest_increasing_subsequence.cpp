/* - the problem can be solved by scanning the input array from left to right once and 
 *   maintaining a vector of increasing numbers
 *   i.e.  10    9    2    5    3    7  101  18  <== input array
 *         10
 *               9
 *                    2
 *                    2    5
 *                    2         3
 *                    2         3    7
 *                    2         3    7  101
 *                    2         3    7       18
 * - each time a new number is read, either a number of the vector is updated or the new number
 *   is appended to the end of the vector
 *   more specifically, try to find the "upperbound" of the new number x:
 *   i.e. find the first number y in the vector that is larger than x, and overwrite y as x
 *        if x is larger than all the numbers of the vector, then append x to the end
 * - as the vector is in a sorted order, the time for finding the upperbound is O(log n)
 *   therefore, the total time required is O(n log n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (int i = 0; i < nums.size(); i++) {
            int ub = upperbound(LIS, nums[i]);
            if (ub == LIS.size())
                LIS.push_back(nums[i]);
            else
                LIS[ub] = nums[i];
        }
        return LIS.size();
    }

    int upperbound(vector<int> &v, int value) {
        int i = 0, j = v.size();
        while (i < j) {
            int mid = (i + j) / 2;
            if (v[mid] < value) i = mid + 1;
            else j = mid;
        }
        return i;
    }
};

int main() {
    int a[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> nums(a, a + 8);
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}
