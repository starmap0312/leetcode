/* problem: compute all possible UNIQUE permutations 
 * uniqueness:
 *   to ensure uniqueness, we sort the numbers before making any choices
 *     nums[0..2] = [ 1, 2, 2 ];
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
        solve(nums, solution, result);
        return result;
    }

    void solve(vector<int> &remaining, vector<int> &solution, vector<vector<int> > &result) {
        // boundary case
        if (remaining.size() == 0) {
            result.push_back(solution);
            return;
        }
        // inductive case
        for (int i = 0; i < remaining.size(); i++) {
            if (i == 0 || remaining[i] != remaining[i - 1]) { // exhaust only distinct choices, ex. [1, 2, 2] will pick only 1 & 2
                int picked = remaining[i];         // make the choice
                remaining.erase(remaining.begin() + i);
                solution.push_back(picked);
                solve(remaining, solution, result);
                solution.pop_back();          // unmake the choice
                remaining.insert(remaining.begin() + i, picked);
            }
        }
    }
};

int main() {
    int a[5] = { 2, 1, 2, 2, 1 };
    vector<int> nums(a, a + 5);
    Solution solution;
    vector<vector<int> > result = solution.permuteUnique(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
