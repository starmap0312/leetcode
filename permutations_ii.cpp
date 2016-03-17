/* - recursion based on a picked set and a remaining set
 *   pick a number from the remaining set, and recursively solve the problem
 * - to ensure uniqueness, don't pick the same value consecutively as both will lead to
 *   exactly the same recursions
 *   i.e.
 *   we first sort the input vector num
 *   we keep a prev value and bypass those iterations that choose the same value as prev
 * - the solution is not very efficient as it uses pass-by-value
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        solve(vector<int>(), nums, result);
        return result;
    }

    void solve(vector<int> picked, vector<int> remaining, vector<vector<int> > &result) {
        if (remaining.size() == 0) {
            result.push_back(picked);
        }
        int prev = INT_MIN;
        for (int i = 0; i < remaining.size(); i++) {
            int val = remaining[i];
            if (prev == val) continue;
            else prev = val;
            // choose the number remaining[i]
            picked.push_back(val);
            remaining.erase(remaining.begin() + i);
            solve(picked, remaining, result);
            // undo the choice
            remaining.insert(remaining.begin() + i, val);
            picked.pop_back();
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
