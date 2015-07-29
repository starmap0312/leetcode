/* 
 */
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long start = 1, end = x / 2;
        long ans = square(start, end, x);
        if (x < ans * ans) return ans - 1;
        else return ans;
    }
    long square(long start, long end, int x) {
        if (start < end) {
            long middle = (start + end) / 2;
            if (x < middle * middle) return square(start, middle - 1, x);
            else if (x > middle * middle) return square(middle + 1, end, x);
            else return middle;
        }
        return (start + end) / 2;
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
