/* - compute the next ugly number, say U_k, using the ugly numbers computed so far, 
 *   i.e. U_1, U_2, ..., U_k
 * - observe that any ugly number can be obtained by multiplied by either 2, 3, or 5 from a
 *   smaller ugly number
 * - for each value 2, 3, or 5, maintain an index that contributes to the next ugly number to
 *   be computed. note that, these indices never decrement
 *   ex. 1  2  3  4  5  ?  <== the initial ugly numbers, ugly[0...4]
 *          i3 i2          <== the indices for each multiplier
 *          i5
 *       the next ugly number is 6, which can be obtained by 2 * 3 == ugly[i3] * 3 or 
 *       3 * 2 == ugly[i2] * 2
 *   after the computation of ugly number 6, increment the values of i3 and i2
 *       1  2  3  4  5  6  ?
 *          i5 i3 i2
 *       the next ugly number is 8, which can be obtained by 4 * 2 == ugly[i2] * 2
 *   after the computation of ugly number 8, increment the value of i2
 *       1  2  3  4  5  6  8  ?
 *          i5 i3    i2
 *   continue in this fashion until the i-th ugly number is computed
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        if (n <= 5) return n;
        int a[] = { 1, 2, 3, 4, 5 };
        vector<int> ugly(a, a + 5);
        int i2 = 2, i3 = 1, i5 = 1;
        while (ugly.size() < n) {
            int minimum = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
            ugly.push_back(minimum);
            while (ugly[i2] * 2 <= minimum) i2++;
            while (ugly[i3] * 3 <= minimum) i3++;
            while (ugly[i5] * 5 <= minimum) i5++;
        }
        return ugly.back();
    }
};

int main() {
    Solution solution;
    cout << solution.nthUglyNumber(10) << endl;
    return 0;
}
