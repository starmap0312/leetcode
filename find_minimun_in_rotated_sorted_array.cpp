#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size();
        while (start < end) {
            int middle = (start + end) / 2;
            if (nums[start] <= nums[middle] && nums[middle] <= nums[end - 1])
                return nums[start];
            if (nums[middle] >= nums[start]) start = middle + 1;
            else {
                if (nums[middle - 1] > nums[middle]) return nums[middle];
                end = middle;
            }
        }
        return nums[start];
    }
};

int main() {
    int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums(a, a + 7);
    Solution solution;
    cout << solution.findMin(nums) << endl;
    return 0;
}
