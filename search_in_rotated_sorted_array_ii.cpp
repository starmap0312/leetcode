/* 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target) return true;
            int left = nums[start], mid = nums[middle], right = nums[end - 1];
            if (isMonotonic(nums, start, middle - 1)) {
                if (target >= left && target <= nums[middle - 1]) end = middle;
                else start = middle + 1;
            } else if (isMonotonic(nums, middle + 1, end - 1)) {
                if (target >= nums[middle + 1] && target <= right) start = middle + 1;
                else end = middle;
            }
        }
        return false;
    }
    bool isMonotonic(vector<int> &nums, int start, int end) {
        if (end - start < 1) return true;
        for (int i = start; i < end; i++)
            if (nums[i] > nums[i + 1]) return false;
        return true;
    }
};

int main() {
    //int a[4] = { 1, 3, 1, 1 }; 
    //vector<int> nums(a, a + 4);
    int a[16] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; 
    vector<int> nums(a, a + 16);
    Solution solution;
    cout << solution.search(nums, 2) << endl;
    return 0;
}
