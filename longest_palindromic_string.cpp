/* - string s("abc"); ==> s.substr(-1, 3) throws exception (index out of range)
 *                    ==> s.substr(5, 1) throws exception (index out of range)
 *                    ==> s.substr(2, 0) returns empty string (string of length 0)
 *                    ==> s.substr(2, INT_MAX) or s.substr(2, -1) returns 2nd suffix (as -1 is converted into
 *                        unsigned int)
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int LCE(string s1, string s2) {
        int j = 0;
        for(int i = s1.size() - 1; i >= 0 && j < s2.size(); i--, j++) {
            if (s1[i] != s2[j]) break;
        }
        return j;
    }
    string longestPalindrome(string s) {
        int odd_index = -1, odd_length = -1;
        for(int i = 0; i < s.size(); i++) {
            int length = LCE(s.substr(0, i), s.substr(i + 1));
            if (length > odd_length) {
                odd_length = length;
                odd_index = i;
            }
        }
        int even_index = -1, even_length = -1;
        for(int i = 0; i < s.size(); i++) {
            int length = LCE(s.substr(0, i + 1), s.substr(i + 1));
            if (length > even_length) {
                even_length = length;
                even_index = i;
            }
        }
        if (2 * odd_length + 1 > 2 * even_length)
            return s.substr(odd_index - odd_length, 2 * odd_length + 1);
        return s.substr(even_index - even_length + 1, 2 * even_length);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("cabbbaca") << endl;
    return 0;
}
