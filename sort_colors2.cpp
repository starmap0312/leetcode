/* - a one-pass linear-time algorithm
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int itr0 = 0, itr1 = 0, itr2 = nums.size() - 1;
        while (itr1 <= itr2) {
            if (nums[itr1] == 0) {
                swap(nums[itr0], nums[itr1]);
                itr0++, itr1++;
            } else if (nums[itr1] == 1) {
                itr1++;
            } else {
                swap(nums[itr1], nums[itr2]);
                itr2--;
            }
        }
    }
};

int main() {
    int a[] = { 0, 1, 2, 1, 2, 1, 1, 0 };
    vector<int> nums(a, a + 8);
    Solution solution;
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
