/* - scan the input numbers from left to right
 *   during the scan, maintain an index j that keeps track of the processed non-zeroes
 *   seen so far
 *   i.e. [ non-zeroes ] [ zeroes ] [ unread numbers ]
 *                         j          i
 *   if read a non-zero number, swap numbers nums[i] and nums[j]
 *   next, increment index j as one more non-zero number is read
 *   ex.  0    1    0    3    12  ==> input array
 *        j,i
 *        0    1    0    3    12  ==> swap(nums[i], nums[j]); j++;
 *        j    i
 *        1    0    0    3    12
 *             j    i
 *        1    0    0    3    12  ==> swap(nums[i], nums[j]); j++;
 *             j         i
 *        1    3    0    0    12  ==> swap(nums[i], nums[j]); j++;
 *                  j         i
 *        1    3    12    0   0   ==> finished
 *                        j       i
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (nums[j] == 0) {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
        }
    }
};

int main() {
    int a[] = { 1, 3, 12, 0, 0 };
    vector<int> nums(a, a + 5);
    Solution solution;
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
