#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size(), index = -1;
        while (start < end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target) {
                index = middle;
                break;
            } else if (nums[middle] > target) {
                index = middle;
                end = middle;
            } else start = middle + 1;
        }
        if (index == -1) index = nums.size();
        return index;
    }
};

int main() {
    int a[4] = { 1, 3, 5, 6 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.searchInsert(nums, 5) << endl;
    cout << solution.searchInsert(nums, 2) << endl;
    cout << solution.searchInsert(nums, 7) << endl;
    cout << solution.searchInsert(nums, 0) << endl;
    return 0;
}
