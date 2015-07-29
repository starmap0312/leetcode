/* - a + b + c == 0, without loss of generality we can assume c <= a && c <= b
 * - once the input sequence is sorted, for a fixed c, to find a + b = -c requries only O(N) time
 * - by utilizing the monotonic property: n_j + n_k > -n_i ==> n_j + n_k' > -n_i for all k' > k
 * - as we aim at unique solutions, there is no need to try for the same c value. therefore,
 *   if a c value has been tried, bypass it and continue to the next c value in the for-loop and 
 *   while-loop
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue; // bypass to avoid repeated c value
            int c = nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j - 1] == nums[j]) { // bypass to avoid repeated c value
                    j++;
                    continue;
                }
                int a = nums[j], b = nums[k];
                if (a + b < -c) j++;
                else if (a + b > -c) k--;
                else { // a + b == -c
                    vector<int> solution;
                    solution.push_back(c), solution.push_back(a), solution.push_back(b);
                    result.push_back(solution);
                    j++;
                }
            }
        }
        return result;
    }
};

int main() {
    int a[6] = { -1, 0, 1, 2, -1, -4 };
    vector<int> nums(a, a + 6);
    Solution solution;
    vector<vector<int> > result = solution.threeSum(nums);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
