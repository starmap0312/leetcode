/* - string s; ==> s = '0' + s; s = s + "123"; one can append/prepend a char/string to a string
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "") return b;
        if (b == "") return a;
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        char carry = '0';
        while (i >= 0 && j >= 0) {
            if (a[i] == '0' && b[j] == '0') { 
                result = carry + result;
                i--; j--; 
                carry = '0';
            } else if (a[i] == '1' && b[j] == '1') {
                result = carry + result;
                i--; j--; 
                carry = '1';
            } else {
                result = (carry == '0'? '1': '0') + result;
                i--; j--; 
            }
        }
        while (i >= 0) {
            if (carry == '0') result = a[i] + result;
            else {
                if (a[i] == '0') {
                    result = carry + result;
                    carry = '0';
                } else result = '0' + result;
            }
            i--;
        }
        while (j >= 0) {
            if (carry == '0') result = b[j] + result;
            else {
                if (b[j] == '0') {
                    result = carry + result;
                    carry = '0';
                } else result = '0' + result;
            }
            j--;
        }
        if (carry == '1') result = '1' + result;
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}
