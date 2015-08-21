/* - the problem assumes that the input numbers are in the range between 0 and INT_MAX
 * - to achieve linear-time complexity: use radix sort to sort the input numbers
 *   sort by the least significant bit in place first, sort by the next bit, and finally 
 *   sort by the most significant bit
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<int> back(nums.size());
        for (int i = 0; i < 31; i++) {
            int frontSize = 0, backSize = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & (1 << i)) == 0) {
                    nums[frontSize] = nums[j];
                    frontSize++;
                } else {
                    back[backSize] = nums[j];
                    backSize++;
                }
            }
            for (int j = 0; j < backSize; j++)
                nums[frontSize + j] = back[j];
        }
        int maxGap = INT_MIN, prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - prev > maxGap) maxGap = nums[i] - prev;
            prev = nums[i];
        }
        return maxGap;
    }
};

int main() {
    int a[] = { 1,1,1,1,1,5,5,5,5,5};
    vector<int> nums(a, a + 10);
    Solution solution;
    cout << solution.maximumGap(nums) << endl;
    return 0;
}
