#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int minimun = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < minimun) minimun = nums[i];
        return minimun;
    }
};

int main() {
    int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums(a, a + 7);
    Solution solution;
    cout << solution.findMin(nums) << endl;
    return 0;
}
