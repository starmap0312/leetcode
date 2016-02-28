/* - the algorithms for finding the upperbound and the lowerbound of a target value
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // returns one element that is equal to target
    // if there is not such element, returns the first element greater than target
    int binarySearch(vector<int> nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        return start;
    }

    // returns the upperbound of target, i.e. the first element greater than target
    int upperbound(vector<int> nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] <= target) start = mid + 1;
            else end = mid;
        }
        return start;
    }

    // returns the lowerbound of target, i.e. the first element greater than or equal to target
    int lowerbound(vector<int> nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        return start;
    }
};

int main() {
    int a[] = { 1, 2, 2, 2, 3 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.binarySearch(nums, 2) << endl;
    cout << solution.upperbound(nums, 2) << endl;
    cout << solution.lowerbound(nums, 2) << endl;
    return 0;
}
