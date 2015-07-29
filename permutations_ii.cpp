/* - to realize unique solutions, when recursive choose the options, don't try the same value
 *   twice as both will lead to exactly the same recursions
 *   so sort the input vector num, keep a prev value, and bypass those iterations that choose
 *   the same value as prev
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        runPermutation(vector<int>(), nums);
        return result;
    }
    void runPermutation(vector<int> selected, vector<int> rest) {
        if (rest.size() == 0) {
            result.push_back(selected);
        }
        int prev = INT_MIN;
        for (int i = 0; i < rest.size(); i++) {
            int val = rest[i];
            if (prev == val) continue;
            else prev = val;
            selected.push_back(val);
            rest.erase(rest.begin() + i);
            runPermutation(selected, rest);
            rest.insert(rest.begin() + i, val);
            selected.pop_back();
        }
    }
private:
    vector<vector<int> > result;
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
