/* - traverse the input numbers while maintaining a list of strictly increasing numbers
 *   ex.
 *                    a3
 *                     x
 *
 *               a2             
 *                x
 *        a1   <--------------- o a4
 *         x
 *
 *    the number a2 in the list will be replaced by number a4
 *    number a4 represents the smallest number in a list of increasing numbers of size 2
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int i = 0; i < nums.size(); i++) {
            int index = upperbound(seq, nums[i]);
            if (seq.size() == index) seq.push_back(nums[i]);
            else seq[index] = nums[i];
        }
        return seq.size();
    }

    int upperbound(vector<int> &seq, int target) {
        int start = 0, end = seq.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (seq[mid] == target) return mid;
            else if (seq[mid] < target) start = mid + 1;
            else end = mid;
        }
        return start;
    }
};

int main() {
    int a[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> nums(a, a + 8);
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}
