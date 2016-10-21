/* - the algorithms for finding the upperbound and the lowerbound of a target value
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // upperbound: first element > target
    // ex.         2   2   2   3   3   3   3   4
    //             ^           ^               ^    ^
    //   target    1           2               3    4
    int upperbound(vector<int> nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > target) end = mid;
            else start = mid + 1;
        }
        return start;
    }

    // lowerbound: first element >= target 
    // ex.         2   2   2   3   3   3   3   4
    //             ^           ^               ^    ^
    //   target   1,2          3               4    5
    int lowerbound(vector<int> nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        return start;
    }
};

int main() {
    int a[] = { 1, 2, 2, 2, 3 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.upperbound(nums, 2) << endl;
    cout << solution.lowerbound(nums, 2) << endl;
    return 0;
}
