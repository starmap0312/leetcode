/* - no need to #include <climits> to use INT_MAX and INT_MIN
 * - no need to #include <string> to use string type
 */
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    Solution() { num = 0; sign = 0;}
    int myAtoi(string str);
private:
    int toDigit(char c);
    void addDigit(char c);
    int num;
    int sign;
};

int Solution::myAtoi(string str) {
    for(int i = 0; i < str.size(); i++) {
        if (sign == 0 && str[i] == ' ') { }
        else if (sign == 0 && str[i] == '+') { sign = 1;}
        else if (sign == 0 && str[i] == '-') { sign = -1;}
        else if (sign == 0 && toDigit(str[i]) != -1) { sign = 1; addDigit(str[i]); }
        else if (sign == 0 && toDigit(str[i]) == -1) { break; }
        else if (toDigit(str[i]) == -1) { break; }
        else {
            addDigit(str[i]);
            if (sign < 0 && num > 0) num = num * sign;
        }
    }
    return num;
}

void Solution::addDigit(char c) {
    if (num >= 0) {
        if (num > (INT_MAX - toDigit(c))/10) num = INT_MAX;
        else num = num * 10 + toDigit(c);
    } else {
        if (num < (INT_MIN + toDigit(c))/10) num = INT_MIN;
        else num = num * 10 - toDigit(c);
    }
}

int Solution::toDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else return -1;
}

int main() {
    Solution solution;
    cout << solution.myAtoi("    10522545459") << endl;
    cout << INT_MAX << endl;
    return 0;
}
