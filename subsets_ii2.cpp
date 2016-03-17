/* - exhaust all possible chocies using recursion
 *   first, sort the input sequence
 *   next, determine the next number to be picked between index..max_num
 * - to ensure the uniqueness, we do not pick two consecutive identical numbers
 *   this technique is quite generic and should pay attention to it
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> choices;
        subsets(nums, 0, choices, result);
        return result;
    }

    void subsets(vector<int> &nums, int index, vector<int> &choices, vector<vector<int> > &result) {
        result.push_back(choices);
        for (int i = index; i < nums.size(); i++) {
            // bypass if the number is equal to its predecessor (always pick a different number)
            if (i > index && nums[i] == nums[i - 1]) continue;
            choices.push_back(nums[i]); // choose nums[i]
            subsets(nums, i + 1, choices, result);
            choices.pop_back(); // undo the choice
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1), nums.push_back(1);
    Solution solution;
    vector<vector<int> > result = solution.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        int j;
        for (j = 0; j < (int)result[i].size() - 1; j++)
            cout << result[i][j] << ",";
        if (result[i].size() > 0) cout << result[i][j];
        cout << "]" << endl;
    }
    return 0;
}
