/* - in order to achieve nearly linear time, use a reverse mapping from value to vector index
 *   first, traverse the input numbers and construct a hash map from value to index
 *   next, check each number if it can be extended to both ends, and record the maximum extension
 * - remember to erase visited numbers in the hash map to speed up the computation
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> toIndex;
        for (int i = 0; i < nums.size(); i++)
            toIndex[nums[i]] = i;
        int maxLength = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            toIndex.erase(nums[i]);
            int x = nums[i] - 1, length = 1;
            while (toIndex.find(x) != toIndex.end()) {
                toIndex.erase(x);
                x--, length++;
            }
            x = nums[i] + 1;
            while (toIndex.find(x) != toIndex.end()) {
                toIndex.erase(x);
                x++, length++;
            }
            if (length > maxLength) maxLength = length;
        }
        return maxLength;
    }
};

int main() {
    int a[] = { 100, 4, 200, 1, 3, 2 };
    vector<int> nums(a, a + 6);
    Solution solution;
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}
