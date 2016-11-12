/* - illustration 
 *   ex.
 *         10    9    2    5    3    7  101  18  <== input array
 *         10
 *               9
 *                    2
 *                    2    5
 *                    2         3
 *                    2         3    7
 *                    2         3    7  101
 *                    2         3    7       18  <== LIS
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
            if (ub == LIS.size()) {
                LIS.push_back(nums[i]);
            } else {
                LIS[ub] = nums[i];
            }
        }
        return LIS.size();
    }

    int upperbound(vector<int> &v, int value) {
        int i = 0, j = v.size();
        while (i < j) {
            int mid = (i + j) / 2;
            if (v[mid] > value) {
                j = mid;
            } else {
                i = mid + 1;
            }
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
