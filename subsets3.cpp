/* - if the sub-problem of size n - 1 is solved, consider one more element which can be added
 *   or not added into the answer, so make one copy of the answer and add the element into
 *   the answer. The answer and the added copy together constitue the answer of the problem
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int> > copy = result;
            addElement(copy, nums[i]);
            result.insert(result.end(), copy.begin(), copy.end());
        }
        return result;
    }
    void addElement(vector<vector<int> > &v, int n) {
        for (int i = 0; i < v.size(); i++) {
            v[i].push_back(n);
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1), nums.push_back(2), nums.push_back(3);
    Solution solution;
    vector<vector<int> > result = solution.subsets(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
