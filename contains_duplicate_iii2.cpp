/* - queue<int> q and priority_queue<int> p; ==> use q.front() to get the first-in element
 *                                               use p.top() to get the minimun element
 *                                               use q.push(3) and p.push(3) to insert element
 *                                               use q.pop() and p.pop() to remove element
 * - set<int>, multiset<int>, map<int, int> resembles balanced binary search trees
 *   you can use memeber function: lower_bound(key) and upper_bound(key) to binary search for key
 *   time complexity: worst case: O(log N)
 * - unordered_set<int> s; and unordered_map<int> mp; has no lower_bound() member function
 *   to check if key is in, use (s.find(key) == s.end()) and (mp.find(key) == mp.end())
 *   time complexity: average case: O(1) and worst case: O(N)
 * - set<int> s; multiset<int> ms; ==> use s.insert(3), ms.insert(3) to insert key
 *                                     use s.erase(3), ms.erase(3) to remove key
 * - set<int>, multiset<int> ==> lower_bound(key) finds first element greater-than-or-equal-to (>=)
 *                               upper_bound(key) finds first element strictly-greater (>)
 *   ex.   3, 4, 4, 4, 5, 7, 7, 7, 8
 *            |_ lower_bound(4)      |_ upper_bound(8) == end()
 *         |_ lower_bound(2) == upper_bound(2) == begin()
 *                     |_ upper_bound(4)
 *                                   |_ lower_bound(9) == upper_bound(9) == end()
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0) return false;
        if (nums.size() > 0) {
            multiset<long> bst;
            for (int i = 1; i < nums.size(); i++) {
                if (i <= k) {
                    bst.insert(nums[i - 1]);
                } else { // maintain a sliding window
                    bst.insert(nums[i - 1]); // append to the last element
                    bst.erase(nums[i - k - 1]); // remove the first element
                }
                if (hasElement(bst, nums[i] - (long)t, nums[i] + (long)t))
                    return true;
            }
        }
        return false;
    }
    bool hasElement(multiset<long> &bst, long lb, long ub) {
        if (bst.lower_bound(lb) == bst.end() || bst.upper_bound(ub) == bst.begin() ||
            bst.lower_bound(lb) == bst.upper_bound(ub))
            return false;
        return true;
    }
};

int main() {
    int a[10] = {0,10,22,15,0,5,22,12,1,5};
    vector<int> nums(a, a + 10);
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, 3, 3) << endl;
    return 0;
}
