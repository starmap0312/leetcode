/* - atoi("123") takes only C-style string, hence string s = "123" ==> atoi(s.c_str()) converts s into int
 * - string s1 = "45", s2 = "123"; ==> (s1 > s2) == true
 * - to_string("123") == 123
 * - string(5, '0') == string("00000"), initialize a string of '0' with length 5
 * - string s = "123"; ==> s.size() is unsigned int, so (s.size() - 5 > 0), needs to convert (int)s.size()
 */
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() < num2.size()) swap(num1, num2);
        if (!exceedIntMax(num1) && !exceedIntMax(num2)) {
            int n1 = atoi(num1.c_str()), n2 = atoi(num2.c_str());
            if (n2 <= INT_MAX / n1) return to_string(n1 * n2);
        }
        int x = (int)num1.size() / 2;
        string first_half = multiply(prefix(num1, x), num2);
        string second_half = multiply(suffix(num1, x), num2);
        return add(first_half + string(x, '0'), second_half);
    }
    string add(string num1, string num2) {
        if (num1 == "0") return num2;
        if (num2 == "0") return num1;
        if (num1.size() < num2.size()) swap(num1, num2);
        if (!exceedIntMax(num1) && !exceedIntMax(num2)) {
            int n1 = atoi(num1.c_str()), n2 = atoi(num2.c_str());
            if (n1 <= INT_MAX - n2) {
                string sum = to_string(n1 + n2);
                int zeros = (int)num1.size() - sum.size();
                if (zeros > 0) sum = string(zeros, '0') + sum;
                return sum;
            }
        }
        int x = (int)num1.size() / 2;
        string first_half= add(prefix(num1, x), prefix(num2, x)); 
        string second_half = add(suffix(num1, x), suffix(num2, x));
        if (second_half.size() > x) {
            first_half = add(first_half, "1");
            second_half = second_half.substr(1);
        }
        return first_half + second_half;
    }
    bool exceedIntMax(const string &num) {
        string int_max = to_string(INT_MAX);
        if (num.size() > int_max.size()) return true;
        else if (num.size() < int_max.size()) return false;
        else return (num > int_max);
    }
    string prefix(const string &num, int x) {
        if ((int)num.size() - x > 0) return num.substr(0, num.size() - x);
        else return "0";
    }
    string suffix(const string &num, int x) {
        if ((int)num.size() - x > 0) return num.substr(num.size() - x);
        else return num;
    }
};

int main() {
    Solution solution;
    cout << solution.multiply("723730354938009379", "9749177200397747152893304399217101120")<< endl;
    return 0;
}
