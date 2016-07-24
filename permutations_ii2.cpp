/* problem: compute all possible UNIQUE permutations 
 * ex. input:
 *       nums[0..2] = [ 2, 1, 2 ]; 
 *     answer:
 *       1 2 2 
 *       2 1 2 
 *       2 2 1 
 * use recursion:
 *   initially, all numbers are unpicked
 *   pick a number from the unpicked set and continue until all numbers are picked
 * uniqueness:
 *   to ensure uniqueness, we sort the numbers before making any choices
 *     nums[0..2] = [ 1, 2, 2 ];
 *   when exhausting all choices, use an addition variable for remembering the last choice
 *     do not make the same chocie as the last choice
 *     this ensures that all permutations outputed will be different
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
        vector<bool> picked(nums.size(), false); // use a bool vector to record if a number is picked
        solve(nums, picked, solution, result);
        return result;
    }

    void solve(vector<int> &nums, vector<bool> &picked, 
        vector<int> &solution, vector<vector<int> > &result) {
        // boundary case
        if (solution.size() == nums.size()) {
            result.push_back(solution);
        }
        int prev = -1;
        for (int i = 0; i < nums.size(); i++) { // make all possible choices
            if (picked[i] == false) {           // if the number nums[i] is not yet picked
                if (prev != -1 && nums[i] == nums[prev]) { // encounter the same choice as the last choice
                    continue;                              // bypass the choice
                }
                prev = i;
                picked[i] = true;               // make a choice: pick nums[i]
                solution.push_back(nums[i]);
                solve(nums, picked, solution, result);
                solution.pop_back();            // unmake the choice
                picked[i] = false;
            }
        }
    }
};

int main() {
    int a[3] = { 2, 1, 2 };
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
