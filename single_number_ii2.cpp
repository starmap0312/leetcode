/* - int A[10] = { 0 }; ==> initialize an array to all values equal to 0
 * - int a = 2; ==> a << 2 shifts all the bits of a to the left by 2 (0010 ==> 1000)
 * - we compute the amount of 1's of the i-th bit, i = 0, 1, ..., 31, of all the numbers
 *   as all the numbers except one appear exactly three times, the computed amount mod by 3 will
 *   give us the i-th bit of the single number
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = { 0 };
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) count[i]++;
            }
            count[i] = count[i] % 3;
        }
        int result = 0;
        for (int i = 0; i < 32; i++) result += (count[i] << i);
        return result;
    }
};

int main() {
    Solution solution;
    int a = 2;
    cout << (a << 2) << endl;
    return 0;
}
