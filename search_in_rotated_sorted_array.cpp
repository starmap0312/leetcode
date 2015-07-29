/* - binary search has two implementations:
 *   use recursion: 
 *   int search(vector<int> &nums, int start, int end, int target) {
 *       if (start >= end) return -1;
 *       int middle = (start + end) / 2;
 *       if (nums[middle] == target) return middle;
 *       else if (nums[middle] < target) return search(nums, middle + 1, end, target);
 *       else return search(nums, start, middle, target);
 *   }
 *   use iteration:
 *   int search(vector<int> &nums, int start, int end, int target) {
 *       int start = 0, end = nums.size();
 *       while (start < end) {
 *           int middle = (start + end) / 2;
 *           if (nums[middle] == target) return middle;
 *           else if (nums[middle] < target) start = middle + 1;
 *           else end = middle;
 *       }
 *       return -1;
 *   }
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target) return middle;
            if (nums[start] <= nums[middle]) {
                if (target < nums[start] || target > nums[middle]) start = middle + 1;
                else end = middle;
            } else if (nums[middle] < nums[end - 1]) {
                if (target <= nums[middle] || target > nums[end - 1]) end = middle;
                else start = middle + 1;
            }
        }
        return -1;
    }
};

int main() {
    //int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
    //vector<int> nums(a, a + 7);
    int a[2] = { 1, 3 };
    vector<int> nums(a, a + 2);
    Solution solution;
    cout << solution.search(nums, 1) << endl;
    return 0;
}
