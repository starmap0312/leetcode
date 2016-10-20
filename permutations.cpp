/* - exhaust all possible of choices using recursion
 *   pick a number from the remaining set
 *   add the number to the picked set and remove from the remaining set
 *   recursively solve the problem based on the picked and remaining sets
 * - the approach utilizes many pass-by-values and therefore is not time-efficient
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        runPermutation(vector<int>(), nums, result);
        return result;
    }

    void runPermutation(vector<int> picked, vector<int> remaining, vector<vector<int> >&result) {
        if (remaining.size() == 0) {
            result.push_back(picked);
        }
        for (int i = 0; i < remaining.size(); i++) {
            int val = remaining[i];
            // choose the i-th number of the remaining set
            picked.push_back(val);
            remaining.erase(remaining.begin() + i);
            runPermutation(picked, remaining, result);
            // undo the choice
            remaining.insert(remaining.begin() + i, val);
            picked.pop_back();
        }
    }
};

int main() {
    int a[] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    Solution solution;
    vector<vector<int> > result = solution.permute(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
