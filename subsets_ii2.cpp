/* - use recursion, for all chocies that can be made, two consecutive identical choices 
 *   need not to be made twice to ensure uniqueness of the answer
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> list;
        subsets(nums, 0, list);
        return result;
    }
    void subsets(vector<int> &nums, int index, vector<int> &list) {
        result.push_back(list);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            list.push_back(nums[i]);
            subsets(nums, i + 1, list);
            list.pop_back();
        }
    }
private:
    vector<vector<int> > result;
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
