/* - an O(n) time and O(1) space algorithm: use two candidate numbers and two counts
 *   the algorithm is correct due to the fact that the majority number is deposited in the
 *   candidates large enough, or the majority number decrements the counts of both candidates
 *   to zero and becomes the new candidate
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1, count1 = 0, candidate2 = -1, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        if (checkMajority(nums, candidate1)) result.push_back(candidate1);
        if (checkMajority(nums, candidate2)) result.push_back(candidate2);
        return result;
    }
    bool checkMajority(vector<int> &nums, int candidate) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == candidate) count++;
        if (count > nums.size() / 3) return true;
        else return false;
    }
};

int main() {
    int a[] = { 5, 1, 3, 2, 2, 1, 2, 2, 1, 2, 1, 1 };
    vector<int> nums(a, a + 12);
    Solution solution;
    vector<int> result = solution.majorityElement(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
