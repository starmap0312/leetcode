/* - the problem is a natural extention of 3sum problem, with one more for-loop
 *   notice where to bypass the loop iteration to avoid repeated solutions 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int l = 0; l < nums.size(); l++) {
            if (l > 0 && nums[l - 1] == nums[l]) continue; // bypass
            int d = nums[l];
            for (int i = l + 1; i < nums.size(); i++) {
                if (i > l + 1 && nums[i - 1] == nums[i]) continue; // bypass
                int c = nums[i];
                int j = i + 1, k = nums.size() - 1;
                while (j < k) {
                    if (j > i + 1 && nums[j - 1] == nums[j]) { // bypass
                        j++;
                        continue;
                    }
                    int a = nums[j], b = nums[k];
                    if (a + b < target - c - d) j++;
                    else if (a + b > target - c - d) k--;
                    else { // a + b == target - c - d
                        vector<int> solution;
                        solution.push_back(d), solution.push_back(c);
                        solution.push_back(a), solution.push_back(b);
                        result.push_back(solution);
                        j++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    int a[6] = { 1, 0, -1, 0, -2, 2 };
    vector<int> nums(a, a + 6);
    Solution solution;
    vector<vector<int> > result = solution.fourSum(nums, 0);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
