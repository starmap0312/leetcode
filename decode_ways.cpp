/* - a recursive approach which takes long time as many subproblems are overlapping
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() <= 1) return 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
            return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
        else
            return numDecodings(s.substr(1));
    }
};

int main() {
    Solution solution;
    cout << solution.numDecodings("12") << endl;
    return 0;
}
