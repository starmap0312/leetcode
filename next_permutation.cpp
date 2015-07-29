#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int branchIndex = findBranchNum(nums);
        if (branchIndex == -1) {
            sort(nums.begin(), nums.end());
        } else {
            int nextIndex = findNextNum(nums, branchIndex);
            swap(nums[branchIndex], nums[nextIndex]);
            sort(nums.begin() + branchIndex + 1, nums.end());
        }
    }
    int findBranchNum(vector<int> &nums) {
        int maximun = INT_MIN, branchIndex;
        for (branchIndex = nums.size() - 1; branchIndex >=0; branchIndex--) {
            if (nums[branchIndex] < maximun) return branchIndex;
            else maximun = max(maximun, nums[branchIndex]);
        }
        return branchIndex;
    }
    int findNextNum(vector<int> &nums, int branchIndex) {
        int minimun = INT_MAX, nextIndex;
        for (int i = branchIndex + 1; i < nums.size(); i++) {
            if (nums[i] > nums[branchIndex] && nums[i] < minimun) {
                minimun = nums[i];
                nextIndex = i;
            }
        }
        return nextIndex;
    }
};

int main() {
    int a[3] = { 1, 1, 5 };
    vector<int> nums(a, a + 3);
    Solution solution;
    solution.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
