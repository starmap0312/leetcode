#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(lowerbound(nums, target));
        result.push_back(upperbound(nums, target));
        return result;
    }
    int lowerbound(vector<int> &nums, int target) {
        int start = 0, end = nums.size(), index = -1;
        while (start < end) {
            int middle = (start + end) / 2;
            if (target == nums[middle]) end = index = middle;
            else if (target < nums[middle]) end = middle;
            else start = middle + 1;
        }
        return index;
    }
    int upperbound(vector<int> &nums, int target) {
        int start = 0, end = nums.size(), index = -1;
        while (start < end) {
            int middle = (start + end) / 2;
            if (target == nums[middle]) { index = middle; start = middle + 1; }
            else if (target > nums[middle]) start = middle + 1;
            else end = middle;
        }
        return index;
    }
};

int main() {
    int a[6] = { 5, 7, 7, 8, 8, 10 };
    vector<int> nums(a, a + 6);
    Solution solution;
    vector<int> result = solution.searchRange(nums, 8);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
