/* - exhaust all possible chocies using recursion
 *     determine the next number to be picked
 * - to ensure the uniqueness, we
 *     sort the input sequence and check the value of the index to be picked (see if it's the value first-seen)
 *     this technique is quite generic and should pay attention to it
 *
 *   ex. 0 1 2 3 4 5 6    index
 *       1 2 2 2 2 3 3 => nums: input values (sorted)
 *       |           |
 *       ... index ...
 *           |.index.|
 *              ..
 *   (without the uniqueness constraint)
 *     we can decide any number from index..nums.size() to be the next index picked
 *
 *   (with the uniqueness constraint)
 *     we bypass those indices with value already seen
 *     i.e. for i in index..nums.size()
 *              if (i > index and nums[i] == nums[i - 1]) { // the value is not first seen
 *                  continue;                               // bypass the iteration
 *              }
 *     note that any number of a specific value can be picked as index increments, and no duplicated
 *       answer will be outputed
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> solution;
        subsets(nums, 0, solution, result);
        return result;
    }

    void subsets(vector<int> &nums, int index, vector<int> &solution, vector<vector<int> > &result) {
        // no base case for this problem, as we are recording every possible subsets
        result.push_back(solution);
        // inductive case: pick a number from index..nums.size() and only those numbers first-seen to
        // ensure uniqueness
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
               // do not make the same choice to ensure uniqueness
                continue;
            }
            solution.push_back(nums[i]);            // make a choice
            subsets(nums, i + 1, solution, result);
            solution.pop_back();                    // unmake the choice
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2), nums.push_back(1), nums.push_back(2);
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
