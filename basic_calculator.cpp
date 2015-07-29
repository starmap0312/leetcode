/* - use two stacks, one for numbers and one for operators
 * - when reads a '+' or '-', push into the operator stack
 * - when reads a ')' or 'number', pop two numbers from the number stack and perform the 
 *   operator in the operator stack
 * - when reads a '(', parse and push the next number to number stack, as the calculation
 *   enters a further layer
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') { }
            else if (s[i] == '(') {
                i++;
                nums.push(readNumber(s, i));
            } else if (s[i] == ')') {
                operate();
            } else if (s[i] == '+' || s[i] == '-') {
                operators.push(s[i]);
            } else {
                nums.push(readNumber(s, i));
                operate();
            }
        }
        return nums.top();
    }
    void operate() {
        if (operators.size() > 0 && nums.size() > 1) {
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            if (operators.top() == '+') nums.push(num1 + num2);
            else nums.push(num1 - num2);
            operators.pop();
        }
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
private:
    stack<int> nums;
    stack<char> operators;
};

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution solution;
    cout << solution.calculate(s) << endl;
    return 0;
}
