/* - the problem can be solved via dynamic programming:
 *   permutations of i numbers can be obtained using permutations of i - 1 numbers
 *   ex.  permutations of 2 numbers
 *          1 2
 *          2 1
 *        permutations of 3 numbers
 *          insert 3 into each of the positions of vector [1, 2]
 *          (3)  1   2
 *           1  (3)  2
 *           1   2  (3)
 *          insert 3 into each of the positions of vector [2, 1]
 *          (3)  2   1
 *           2  (3)  1
 *           2   1  (3)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.size() == 0) return result;
        result.push_back(vector<int>(1, nums[0]));
        for (int i = 1; i < nums.size(); i++) {
            vector<vector<int> > next;
            for (int j = 0; j < result.size(); j++) {
                // duplicate permuation result[j] and insert num[i] into each of the positions
                // ex. [1] + 2 ==> [[2, 1], [1, 2]]
                for (int k = 0; k <= result[j].size(); k++) {
                    next.push_back(result[j]);
                    next.back().insert(next.back().begin() + k, nums[i]);
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
    vector<vector<int> > rc = solution.permute(nums);
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++)
            cout << rc[i][j] << " ";
        cout << endl;
    }
    return 0;
}
