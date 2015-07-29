/* - both set<int> s, and map<int, int> mp have iterators and find member functions
 * - use set<int>::iterator and map<int, int>::iterator to traverse set and map in a sorted order
 *   i.e. for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) { ... }
 *        for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) { ... }
 * - set and map resembles balanced binary search tree, and can find element in (Log N) time, 
 *   using member function s.lower_bound(key), mp.lower_bound(key)
 * - use (s.find(3) != s.end()), (mp.find(3) != mp.end()) to determine if a key exists 
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() > 0) {
            vector<int> sorted_nums = nums;
            set<int> dup;
            unordered_map<int, vector<int> > mp;
            sort(sorted_nums.begin(), sorted_nums.end());
            for (int i = 1; i < sorted_nums.size(); i++)
                if (sorted_nums[i - 1] == sorted_nums[i]) dup.insert(sorted_nums[i]);
            for (int i = 0; i < nums.size(); i++)
                if (dup.find(nums[i]) != dup.end()) {
                    if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = vector<int>();
                    mp[nums[i]].push_back(i);
                }
            for (unordered_map<int, vector<int> >::iterator itr = mp.begin(); itr != mp.end();
                itr++) {
                if ((itr -> second).size() < 2) continue;
                for (int i = 1; i < (itr -> second).size(); i++)
                    if (abs((itr -> second)[i - 1] - (itr -> second)[i]) <= k ) return true;
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
