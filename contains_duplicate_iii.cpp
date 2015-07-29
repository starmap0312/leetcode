/* - if you want to traverse a queue without popping out all elements, you need to make a copy
 *   of the original queue and traverse the copied queue instead
 *   i.e. queue<int> copy = original; while (!copy.empty()) { access copy.front(); copy.pop(); }
 *   or you can use a vector instead
 *   i.e. vector<int> v; ==> to traverse, for (int i = 0; i < v.size(); i++) { access v[i]; }
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() > 0) {
            for (int i = 0; i < nums.size(); i++) {
                int minimun = findMin(nums, i - k, i - 1);
                int maximun = findMax(nums, i - k, i - 1);
                if (nums[i] + t >= minimun && nums[i] - t <= maximun)
                    return true;
            }
        }
        return false;
    }
    int findMin(vector<int> &nums, int i, int j) {
        int minimun = INT_MAX;
        for (int k = max(0, i); k <= j; k++)
            if (minimun > nums[k]) minimun = nums[k];
        return minimun;
    }
    int findMax(vector<int> &nums, int i, int j) {
        int maximun= INT_MIN;
        for (int k = max(0, i); k <= j; k++)
            if (maximun > nums[k]) maximun = nums[k];
        return maximun;

    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1), nums.push_back(-1);
    nums.push_back(-3), nums.push_back(2);
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, 2, 0) << endl;
    return 0;
}
