/* - first, use the skill of problem "single number i" to compute the exclusive-or value of
 *   the two singel numbers
 *   ex. 1     2     1     3     2     5                          ==> input array
 *       1 XOR 2 XOR 1 XOR 3 XOR 2 XOR 5  == 3 XOR 5  == 6 (110)  ==> exclusive-or value
 * - observe that since the two single numbers are not equal, the exclusive-or value has 
 *   at least one 1's bit
 * - use the exclusive-or value, we compute the separate value as follows:
 *   ex. exclusive-or value == 6 (110)
 *       we know at least one bit is 1's, use one of the 1's bits as the separate value
 *       i.e. separate value == 4 (100) or 2 (010)
 *       we can use the separate value, ex. 2 (010), to seprate the input numbers as follows:
 *       input number        separate value      AND result
 *       1 (001)       AND   2 (010)         ==  0 (000)     ==> group 1
 *       2 (010)       AND   2 (010)         ==  2 (010)     ==> group 2
 *       1 (001)       AND   2 (010)         ==  0 (000)     ==> group 1
 *       3 (011)       AND   2 (010)         ==  2 (010)     ==> group 2
 *       2 (010)       AND   2 (010)         ==  2 (010)     ==> group 2
 *       5 (101)       AND   2 (010)         ==  0 (000)     ==> group 1
 * - observe that the two single numbers lie in different separated groups:
 *   i.e. group 1: { 1, 1, 5 }, group 2: { 2, 3, 2 }
 * - use the skill of problem "single number i", for each group we can obatin one single number 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int exclusiveOr = 0;
        for (int i = 0; i < nums.size(); i++) {
            exclusiveOr = exclusiveOr ^ nums[i];
        }
        int sep = 1;
        for (int i = 0; i < 32; i++) {
            if ((sep & exclusiveOr) != 0) break;
            sep = sep << 1;
        }
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((sep & nums[i]) == 0)
                a = a ^ nums[i];
            else
                b = b ^ nums[i];
        }
        vector<int> result;
        result.push_back(a), result.push_back(b);
        return result;
    }
};

int main() {
    int a[] = { 1, 2, 1, 3, 2, 5 };
    vector<int> nums(a, a + 6);
    Solution solution;
    vector<int> rc = solution.singleNumber(nums);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}

