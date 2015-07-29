/* - string s; ==> replace(s.begin(), s.end(), 'x', 'y') replaces all characters 'x' in
 *                 string s with character 'y'
 * - string s; ==> s.erase(remove(s.begin(), s.end(), 'x'), s.end()) removes all characters 'x'
 *                 from string s
 *                 remove(s.begin(), s.end(), 'x') returns the end of the resulting string
 *                 ex. s = 'xaaxbxcccx'
 *                         'aabccc'
 *                                 |_ remove(s.begin(), s.end(), 'x') returns iterator to 
 *                                    this position
 *                 so erase() method continues to remove the remaining part after removing
 *                 combining the two, the expression turns s into s = 'aabccc'
 * - the problem is solved by keeping a total number, a prev number, and a prev operator
 *   i.e. 15    +      10      +, -, *, -  8
 *        total prevOp prevNum curOp       nextNum
 *   when curOp == '+' or curOp == '-', (15 + 10) can be performed (update total and prevOp)
 *   when curOp == '*' or curOp == '/', (10 *,/ 8) can be performed (update prevNum)
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int total = -1, prev = -1;
        char prevOp = ' ';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (prev == -1) total = total * readNumber(s, ++i);
                else prev = prev * readNumber(s, ++i);
            } else if (s[i] == '/') {
                if (prev == -1) total = total / readNumber(s, ++i);
                else prev = prev / readNumber(s, ++i);
            } else if (s[i] == '+' || s[i] == '-') {
                if (prevOp == ' ') { prevOp = s[i]; continue; }
                if (prevOp == '+') total = total + prev;
                else total = total - prev;
                prevOp = s[i];
                prev = readNumber(s, ++i);
            } else { // read digits
                if (total == -1) total = readNumber(s, i);
                else prev = readNumber(s, i);
            }
        }
        if (prevOp == '+') total = total + prev;
        else if (prevOp == '-') total = total - prev;
        return total;
    }
    int readNumber(string &s, int &i) {
        int sum = 0;
        while (i < s.size() && isDigit(s[i])) {
            sum = sum * 10 + (s[i] - '0');
            i++;
        }
        i--;
        return sum;
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
};

int main() {
    string s = "3+2*2";
    Solution solution;
    cout << solution.calculate(s) << endl;
    return 0;
}
