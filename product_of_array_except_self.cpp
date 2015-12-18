/* - the problem can be solved by scanning the array from left to right, and right to left once
 *   during the scanning, maintain the product of the numbers seen so far
 *   ex.  a1      a2      a3      a4       <- input array
 *        1       a1      a1a2    a1a2a3   <- first scan, from left to right
 *        x       x       x       x
 *        a4a3a2  a4a3    a4      1        <- second scan, from right to left
 *        -----------------------------
 *        a2a3a4  a1a3a4  a1a2a4  a1a2a3   <- final result
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int sum = 1;
        result.push_back(sum);
        for (int i = 0; i < nums.size() - 1; i++) {
            sum = sum * nums[i];
            result.push_back(sum);
        }
        sum = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            sum = sum * nums[i];
            result[i - 1] = result[i - 1] * sum;
        }
        return result;
    }
};

int main() {
    int a[] = { 1, 2, 3, 4 };
    vector<int> nums(a, a + 4);
    Solution solution;
    vector<int> rc = solution.productExceptSelf(nums);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
