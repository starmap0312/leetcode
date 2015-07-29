/* - an O(n) time and O(1) space algorithm: visit the numbers one by one, each number 
 *   can either increment or decrement the count of the candidate number (the candidate 
 *   number is re-assigned if its count becomes zero
 * - the algorithm is correct due to the fact that the majority number will stay as the
 *   candidate number in the end of the traversal: either it is deposited large enough so that
 *   no one can replace it as candidate number, or it decrement the candidate to zero and
 *   becomes the new candidate 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count++;
            } else {
                if (nums[i] == candidate) count++;
                else count--;
            }
        }
        return candidate;
    }
};

int main() {
    int a[] = { 1, 2, 2, 1, 3, 8, 1, 1, 1, 1, 2, 1 };
    vector<int> nums(a, a + 12);
    Solution solution;
    cout << solution.majorityElement(nums) << endl;
    return 0;
}
