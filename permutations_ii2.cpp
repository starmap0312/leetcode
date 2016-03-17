/* - 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> solution;
        vector<bool> picked(nums.size(), false);
        solve(nums, picked, solution, result);
        return result;
    }

    void solve(vector<int> &nums, vector<bool> &picked, 
        vector<int> &solution, vector<vector<int> > &result) {
        // boundary case
        if (solution.size() == nums.size()) {
            result.push_back(solution);
        }
        for (int i = 0; i < nums.size(); i++) {
            // bypass consecutive identical choices to ensure uniqueness
            // otherwise, we re-try the exact same choice of numbers in this iteration
            if (i > 0 && nums[i - 1] == nums[i] && picked[i - 1] == false) continue;
            if (picked[i] == false) {
                picked[i] = true;
                solution.push_back(nums[i]);
                solve(nums, picked, solution, result);
                solution.pop_back();
                picked[i] = false;
            }
        }
    }
};

int main() {
    int a[3] = { 1, 1, 2 };
    vector<int> nums(a, a + 3);
    Solution solution;
    vector<vector<int> > result = solution.permuteUnique(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
