/* - a two-phase algorithm using a hashmap
 *   1) phase 1:
 *      put all (number, index) into the hashmap
 *   2) phase 2:
 *      for each number, check if its complement is in the hashmap with a different index
 *
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rc;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end() && mp[complement] != i) {
                vector<int> rc;
                rc.push_back(i);
                rc.push_back(mp[complement]);
                return rc;
            }
        }
        return rc; 
    }
};

int main() {
    Solution solution;
    int a[3] = { 3, 2, 4 };
    vector<int> nums(a, a + 3);
    vector<int> rc = solution.twoSum(nums, 6);
    for (int i = 0; i < rc.size(); i++) cout << rc[i] << " ";
    cout << endl;
    return 0;
}
