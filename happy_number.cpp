/* - set<int> s; ==> s.insert(3) to insert element, s.find(3) != s.end() to search for element 3
 *                   (s.count(3) > 0)? to check if key 3 is in set s
 */
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> sums;
        while (n != 1) {
            n = sumSquare(n);
            if (sums.find(n) != sums.end()) break;
            else sums.insert(n);
        }
        return (n == 1? true: false);
    }

    int sumSquare(int n) {
        int result = 0;
        while (n > 0) {
            int d = n % 10;
            result += d * d;
            n /= 10;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.isHappy(19) << endl;
    return 0;
}
