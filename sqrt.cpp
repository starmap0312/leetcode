/* - long n; ==> use long if int is not sufficient for large integer computation
 * - use while-loop not recursive function if recursion does not work or while-loop is clearer
 *   in this example, you can not get both start and end when the recursion terminates
 *   so while-loop is a better deal
 */
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long start = 1, end = x / 2;
        while (start < end) {
            long middle = (start + end) / 2;
            if (x < middle * middle) end = middle - 1;
            else if (x > middle * middle) start = middle + 1;
            else start = end = middle;
        }
        long ans = (start + end) / 2;
        if (x < ans * ans) return ans - 1;
        else return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(1) << endl;
    cout << solution.mySqrt(2) << endl;
    cout << solution.mySqrt(3) << endl;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(8) << endl;
    cout << solution.mySqrt(9) << endl;
    cout << solution.mySqrt(2147483647) << endl;
    return 0;
}
