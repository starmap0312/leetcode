#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int i = 0, j = sorted_nums.size() - 1;
        while (i < j) {
            while (sorted_nums[i] + sorted_nums[j] > target) j--;
            if (sorted_nums[i] + sorted_nums[j] == target) break;
            else i++;
        }
        vector<int> result;
        if (i < j) { 
            for (int k = 0; k < nums.size(); k++) {
                if (sorted_nums[i] == nums[k] || sorted_nums[j] == nums[k])
                    result.push_back(k + 1);
                if (result.size() == 2) break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int a[3] = { 3, 2, 4 };
    vector<int> nums(a, a + 3);
    vector<int> result = solution.twoSum(nums, 6);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
