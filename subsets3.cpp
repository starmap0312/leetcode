/* - the problem can be easily solved via dynamic programming
 *   i.e. if the solution to the subproblem of size n - 1 is solved
 *        to compute the solution of the problem of size n
 *        for each subset we can either append the next number to its end or not to append
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
        for (int i = 0; i < nums.size(); i++) { // process the numbers one by one 
            vector<vector<int> > duplicate = result;
            addElement(duplicate, nums[i]);
            result.insert(result.end(), duplicate.begin(), duplicate.end());
        }
        return result;
    }

    void addElement(vector<vector<int> > &v, int num) { // add num to all the vectors of v
        for (int i = 0; i < v.size(); i++) {
            v[i].push_back(num);
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1), nums.push_back(2), nums.push_back(3);
    Solution solution;
    vector<vector<int> > result = solution.subsets(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1 ) cout << result[i][j];
            else cout << result[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
