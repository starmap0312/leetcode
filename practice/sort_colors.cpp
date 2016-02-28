/* - to solve the problem we maintain three indices: index0, index1, and index2, which denote the
 *   next position the next read index0, index1, or index2 should be put at
 *   ex.               index0      index1                  index2
 *         0     0     1     1     0     1     0     2     1     2     2
 *         <-----|     <-----|                                   |------>
 *     case 1) if a 0's is read, swap elements at index0 and index1
 *             increment both index0 and index1 by one
 *     case 2) if a 1's is read, increment index1 by one
 *     case 3) if a 2's is read, swap elements at index1 and index2
 *             decrement index2 by one
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index0 = 0, index1 = 0, index2 = nums.size() - 1;
        while (index1 <= index2) {
            if (nums[index1] == 0) {
                swap(nums[index0], nums[index1]);
                index0++;
                index1++;
            } else if (nums[index1] == 1) {
                index1++;
            } else {
                swap(nums[index1], nums[index2]);
                index2--;
            }
        }
    }
};

int main() {
    int a[] = { 1, 0, 1, 2, 1, 0 };
    vector<int> nums(a, a + 6);
    Solution solution;
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
