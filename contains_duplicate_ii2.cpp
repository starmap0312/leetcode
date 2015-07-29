/* - scan the input sequence vector<int> nums from left to right, utilizes the fact that
 *   at each index i, you only needs to check for the largest j such that nums[j] == nums[i], if
 *   such index j exists
 *   therefore, by maintaining a map<int, int> mp such that mp[k] records the largest index
 *   with value k, the task can be easily completed
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() > 0) {
            unordered_map<int, int> mp;
            for (int i = 0; i < nums.size(); i++) {
                if (mp.find(nums[i]) == mp.end())
                    mp[nums[i]] = i;
                else {
                    int prev = mp[nums[i]];
                    if (i - prev <= k) return true;
                    mp[nums[i]] = i;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1), nums.push_back(-1);
    Solution solution;
    cout << solution.containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}
