/* - the problem is similar to a binary search problem
 *   ex. 1    2    3    4    5    6 ==> versions
 *       O    O    O    X    X      ==> bad version: X
 *       i        mid             j
 *                      i   mid   j
 *                    i,mid  j
 *                    i,j
 *       return version 4 as the first bad version
 * - the tricky part of this problem is that the integer overflow must be considered
 *   therefore, one cannot treat (n + 1) or (i + j) / 2 as valid expression
 *   the following solution deals with the above problem
 */
#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i - 1 < j) {
            int mid = i / 2 + j / 2;
            if (j % 2 == 1) mid++;
            if (i % 2 == 1 && j % 2 == 0) mid++;
            if (isBadVersion(mid)) j = mid - 1;
            else i = mid + 1;
        }
        return i;
    }
};

int main() {
    return 0;
}
