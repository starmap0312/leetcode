/* - the problem can be solved by exhausting all partitions of the string and by using recursion
 *   ex. 199100199  ==> input string
 *       first use two loops to try all choices of the first two partitions
 *       1 9
 *       1 99
 *       1 991
 *       ...
 *       19 9
 *       19 91
 *       ...
 * - once the first two parititons are determined, try all the possibilities of the next 
 *   partition; once the next partition is determined, try the possibilities of the 
 *   next next partition, and continue in this manner until:
 *       1. it is not a valid partition (2 digit numbers with leading '0' or the partition
 *          violates the additive sequence, i.e. subsequent number is not the sum of the
 *          two preceding numbers)
 *       2. the complete string is partitioned
 * - if there is no violation and the complete string is partitioned, return true; otherwise,
 *   return false
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); i++) {
            if (num[0] == '0' && i > 0) continue;
            for (int j = i + 1; j + 1 < num.size(); j++) {
                if (num[i + 1] == '0' && j - i > 1) continue;
                int prev = atoi(num.substr(0, i + 1).c_str());
                int cur = atoi(num.substr(i + 1, j - i).c_str());
                if (solve(num, prev, cur, j + 1))
                    return true;
            }
        }
        return false;
    }

    bool solve(string &num, int prev, int cur, int index) {
        if (index == num.size()) return true;
        for (int i = index; i < num.size(); i++) {
            if (num[index] == '0' && i - index > 0) continue;
            int next = atoi(num.substr(index, i - index + 1).c_str());
            if ((next == prev + cur) && solve(num, cur, next, i + 1))
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isAdditiveNumber("199100199") << endl;
    return 0;
}
