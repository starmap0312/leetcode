#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p_result = INT_MIN, n_result = INT_MIN;
        int max_positive = 0, max_negative = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                max_positive = max(nums[i], max_positive * nums[i]);
                max_negative = max_negative * nums[i];
            } else if (nums[i] < 0) {
                int tmp = max_negative * nums[i];
                max_negative = min(nums[i], max_positive * nums[i]);
                max_positive = tmp;
            } else {
                max_positive = 0;
                max_negative = 0;
            }
            p_result = max(p_result, max_positive);
            n_result = max(n_result, max_negative);
        }
        return (p_result > 0? p_result: n_result);
    }
};
int main() {
    vector<int> nums;
    nums.push_back(-4), nums.push_back(-3), nums.push_back(-2);
    Solution solution;
    cout << solution.maxProduct(nums) << endl;
    return 0;
}
