/* - solve the problem via dynamic programming
 *   if the subproblem of size n - 1 is solved, the problem of size n can be solved by
 *   appending the last number to any of the positions of each permutation
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int> > next;
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k <= result[j].size(); k++) {
                    vector<int> duplicate = result[j];
                    duplicate.insert(duplicate.begin() + k, nums[i]);
                    next.push_back(duplicate);
                }
            }
            result = next;
        }
        return result;
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
