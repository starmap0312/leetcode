/* - first transform the expression into reverse polish notation (RPN); then, evaluate the
 *   RPN expression
 *   ex. 5 + ((1 + 2) x 4) - 3 ==> 5 1 2 + 4 x + 3 -
 * - use an operator stack, i.e. for +, -, *, /, (, )
 *   if read a number, then push to the result
 *   if read +, -, *, -, then pop operators with lower priorioties from the stack and
 *                       push to the result, finally push the read operator to the stack
 *   if read (, then push to the stack
 *   if read ), then pop operators from the stack and push to the result until ( is met
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        vector<string> rpn = convertToRPN(s);
        return evaluateRPN(rpn); 
    }
    int evaluateRPN(vector<string> &rpn) {
        stack<int> nums;
        for (int i = 0; i < rpn.size(); i++) {
            string token = rpn[i];
            if (isDigit(token[0])) nums.push(atoi(token.c_str()));
            else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (token == "+") nums.push(num1 + num2);
                else if (token == "-") nums.push(num1 - num2);
                else if (token == "*") nums.push(num1 * num2);
                else nums.push(num1 / num2);
            }
        }
        return nums.top();
    }
    vector<string> convertToRPN(string s) {
        vector<string> result;
        stack<char> operators;
        for (int i = 0; i < s.size(); i++) {
            if (isDigit(s[i])) {
                result.push_back(readNumber(s, i));
            } else if (isOperator(s[i])) {
                while (operators.size() > 0 && priority(operators.top()) >= priority(s[i])) {
                    result.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(s[i]);
            } else if (s[i] == '(') {
                operators.push(s[i]);
            } else if (s[i] == ')') {
                while (operators.size() > 0 && operators.top() != '(') {
                    result.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.pop();
            }
        }
        while (operators.size() > 0) {
            result.push_back(string(1, operators.top()));
            operators.pop();
        }
        return result;
    }
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        else if (op == '*' || op == '/') return 2;
        else return 0;
    }
    string readNumber(string &s, int &i) {
        string num = "";
        while (i < s.size() && isDigit(s[i])) {
            num += s[i];
            i++;
        }
        i--;
        return num;
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
private:
    stack<int> nums;
    stack<char> operators;
};

int main() {
    string s = "5 + ((1 + 2) * 4) - 3";
    Solution solution;
    cout << solution.calculate(s) << endl;
    return 0;
}
