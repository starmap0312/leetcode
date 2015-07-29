/* - char c = 'B'; ==> function isalnum(c) returns true if c is a alphanumeric character
 *   char c = 'B'; ==> tolower(c) == 'b' is the lower case of c
 *   both do not take string as argument
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string stripped = "";
        for (int i = 0; i < s.size(); i++)
            if (isalnum(s[i])) stripped += s[i];
        return isValid(stripped, 0, stripped.size() - 1);
    }
    bool isValid(string &s, int start, int end) {
        if (start < end) {
            if (tolower(s[start]) == tolower(s[end])) return isValid(s, start + 1, end - 1 );
            else return false;
        } else return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
