/* - only '*' and '/' operators will be performed and consume the numbers in the number stack
 *   all other operators, i.e. '+' and '-', are performed in the end of the program
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> operators;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') { }
            else if (s[i] == '(') {
                i++;
                nums.push(readNumber(s, i));
            } else if (s[i] == ')') {
                if (operators.size() > 0 && (operators.top() == '*' || operators.top() == '/'))
                    operate(operators, nums);
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                operators.push(s[i]);
            } else { // read digits
                nums.push(readNumber(s, i));
                if (operators.size() > 0 && (operators.top() == '*' || operators.top() == '/'))
                    operate(operators, nums);
            }
        }
        stack<int> reversed_nums;
        while (nums.size() > 0) {
            reversed_nums.push(nums.top());
            nums.pop();
        }
        stack<char> reversed_operators;
        while (operators.size() > 0) {
            reversed_operators.push(operators.top());
            operators.pop();
        }
        while (reversed_operators.size() > 0)
            reversed_operate(reversed_operators, reversed_nums);
        return reversed_nums.top();
    }
    void reversed_operate(stack<char> &operators, stack<int> & nums) {
        if (operators.size() > 0 && nums.size() > 1) {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            if (operators.top() == '+') nums.push(num1 + num2);
            else if (operators.top() == '-') nums.push(num1 - num2);
            else if (operators.top() == '*') nums.push(num1 * num2);
            else nums.push(num1 / num2);
            operators.pop();
        }
    }
    void operate(stack<char> &operators, stack<int> & nums) {
        if (operators.size() > 0 && nums.size() > 1) {
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            if (operators.top() == '+') nums.push(num1 + num2);
            else if (operators.top() == '-') nums.push(num1 - num2);
            else if (operators.top() == '*') nums.push(num1 * num2);
            else nums.push(num1 / num2);
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
};

int main() {
    string s = "3+2*2";
    Solution solution;
    cout << solution.calculate(s) << endl;
    return 0;
}
