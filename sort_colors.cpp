/* - the problem can be solved using counting sort
 * - a straitforward approach contains two passes, first to count the colors and next to generate
 *   the sorted sequence
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else count2++;
        }
        for (int i = 0; i < count0; i++) nums[i] = 0;
        for (int i = 0; i < count1; i++) nums[i + count0] = 1;
        for (int i = 0; i < count2; i++) nums[i + count0 + count1] = 2;
    }
};

int main() {
    return 0;
}
