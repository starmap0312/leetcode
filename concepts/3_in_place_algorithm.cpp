/* Given nums = [a1, a2, .., an, b1, b2, .., bn], write an in-place algorithm to rearrange the array to:
 *       nums = [a1, b1, a2, b2, .., an, bn]
 * 1) using an extra array:
 *
 *   i             i+n/2
 *  (1   2   3   4) (5   6   7   8)
 *   ------->        ------->
 *
 *  scan the left and the right subsequence simultaneously, incrementing one single index i
 *
 * 2) in-place algorithm:
 *                   x
 *   1  (2   3   4) (5)  6   7   8 ==> need 3 swaps
 *   1  (5) (2   3   4)  6   7   8
 *
 *                       x
 *   1   5   2  (3   4) (6)  7   8 ==> need 2 swaps
 *   1   5   2  (6) (3   4)  7   8
 *
 *                           x
 *   1   5   2   6   3  (4) (7)  8 ==> need 1 swap
 *   1   5   2   6   3  (7) (4)  8
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rearrange(vector<int> &nums) {
        vector<int> extra;
        for (int i = 0; i < nums.size()/2; i++) {
            extra.push_back(nums[i]);
            extra.push_back(nums[i + nums.size()/2]);
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = extra[i];
        }
    }

    void inplace(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int j = nums.size()/2 + i;
            int length = nums.size()/2 - i - 1;
            while (length > 0) { 
                swap(nums[j - 1], nums[j]);
                j--;
                length--;
            }
        }
    }
};


int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> nums(a, a + 8);
    Solution solution;
    //solution.rearrange(nums);
    solution.inplace(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
