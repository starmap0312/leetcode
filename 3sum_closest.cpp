/* 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dist = INT_MAX, ans;
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
                if (abs(a + b + c - target) < dist) {
                    dist = abs(a + b + c - target);
                    ans = a + b + c;
                }
                if (a + b > -c + target) k--;
                else j++;
            }
        }
        return ans;
    }
};

int main() {
    int a[6] = { -1, 2, 1, -4 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.threeSumClosest(nums, 2) << endl;
    return 0;
}
