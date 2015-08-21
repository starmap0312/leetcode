/* - a straightforward algorithm takes O(n ^ 2) time
 * - use dynamic programming to solve the problem in O(n) time
 *   knowing the answer of substring s[0..i] gives the answer of s[0..i + 1]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        int maxLength = INT_MIN;
        vector<int> ans(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(' || (i - 1 - ans[i - 1]) < 0 || s[i - 1 - ans[i - 1]] == ')')
                ans[i] = 0;
            else {
                if (i - 1 - ans[i - 1] > 0)
                    ans[i] = ans[i - 1] + ans[i - 2 - ans[i - 1]] + 2;
                else
                    ans[i] = ans[i - 1] + 2;
            }
            if (ans[i] > maxLength) maxLength = ans[i];
        }
        return maxLength;
    }
};

int main() {
    string s = "()(()(((((())())((()))(()((())()(()()(()((()))()))))())))))())()())))(()()()())((()()()))()(()(()))())(((()))())(()((()))(()(()))()";
    Solution solution;
    cout << solution.longestValidParentheses(s) << endl;
    return 0;
}
