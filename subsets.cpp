/* - a divide-and-conquer approach using recursion
 *   the recursion: either pick the max number or not pick
 *   ex. input: [1, 5, 3]
 *       solve the subproblem of [1, 3] ==> [[], [1], [3], [1, 3]]
 *       for every subset of the solution to the subproblem
 *       we can either add the max number or not add the max number to the subset
 *       this leads to: [[], [5], [1], [1, 5], [3], [3, 5], [1, 3], [1, 3, 5]]
 * - this approach is time-consuming, as the return solution of the subproblem uses pass-by-value
 * - no need to find the max num if the input vector is first sorted
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums);

private:
    int find_max_index(vector<int> &nums);
    vector<int> erase_max(vector<int> &nums);
};

vector<vector<int> > Solution::subsets(vector<int> &nums) {
    vector<vector<int> > results;
    if(nums.size() == 0) {
        results.push_back(vector<int>());
        return results;
    }
    int max_num = nums[find_max_index(nums)];
    // divide-and-conquer: find all subsets for input set without the max number
    vector<int> no_max_nums = erase_max(nums);
    vector<vector<int> > no_max_subsets = subsets(no_max_nums);
    // for each subset, we can either append the max number to its end or not append
    for (int i = 0; i < no_max_subsets.size(); i++) {
        results.push_back(no_max_subsets[i]);
        no_max_subsets[i].push_back(max_num);
        results.push_back(no_max_subsets[i]);
    }
    return results;
}

int Solution::find_max_index(vector<int> &nums) {
    if(nums.size() == 0) return -1;
    int max_index = 0;
    for(int i = 1; i < nums.size() ; i++)
        if(nums[max_index] < nums[i]) max_index = i;
    return max_index;
}

vector<int> Solution::erase_max(vector<int> &nums) {
    vector<int> results = nums;
    if(nums.size() == 0) return results;
    int max_index = find_max_index(nums);
    results.erase(results.begin() + max_index);
    return results;
}

int main() {
    int n[] = { 3, 5, 1, 8 };
    vector<int> nums(n, n + 4);
    Solution solution;
    vector<vector<int> > rc = solution.subsets(nums);
    for (int i = 0; i < rc.size(); i++) {
        cout << "[";
        for (int j = 0; j < rc[i].size(); j++) {
            if (j == rc[i].size() - 1) cout << rc[i][j];
            else cout << rc[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
