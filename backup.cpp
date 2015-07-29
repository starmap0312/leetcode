#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool negative = false;
        if ((numerator > 0 && denominator < 0) || 
            (numerator < 0 && denominator > 0)) negative = true;
        if (numerator < 0) numerator = numerator * -1;
        if (denominator < 0) denominator = denominator * -1;
        vector<int> quotients, remainders;
        int integer = numerator / denominator;
        int quotient;
        int remainder = numerator % denominator;
        remainders.push_back(remainder);
        int start = -1, end = -1;
        while (remainder != 0) {
            quotient = (remainder * 10) / denominator;
            remainder = (remainder * 10) % denominator;
            quotients.push_back(quotient);
            vector<int>::iterator itr = find(remainders.begin(), remainders.end(), remainder);
            if (itr == remainders.end()) {
                remainders.push_back(remainder);
            } else {
                start = itr - remainders.begin();
                end = remainders.end() - remainders.begin();
                break;
            }
        }
        string result = "";
        if (negative) result = "-";
        if (quotients.size() > 0) result += to_string(integer) + ".";
        else result += to_string(integer);
        for (int i = 0; i < quotients.size(); i++) {
            if (i == start) result += "(";
            result += to_string(quotients[i]);
        }
        if (end != -1) result += ")";
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
