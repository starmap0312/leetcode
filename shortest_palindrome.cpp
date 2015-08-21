/* - a naive quadratic-time algorithm for finding shortest palindrome
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        for (int mid = s.size() / 2; mid >= 0; mid--) {
            int l1 = mid - 1, r1 = mid;
            if (findPalindrome(s, l1, r1)) {
                string r = s.substr(r1);
                reverse(r.begin(), r.end());
                return r + s;
            }
            int l2 = mid - 1, r2 = mid - 1;
            if (findPalindrome(s, l2, r2)) {
                string r = s.substr(r2);
                reverse(r.begin(), r.end());
                return r + s;
            }
        }
        string r = s;
        reverse(r.begin(), r.end());
        return r + s;
    }
    bool findPalindrome(string &s, int &l, int &r) {
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) return false;
            l--, r++;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.shortestPalindrome("aacecaaa") << endl;
    cout << solution.shortestPalindrome("abcd") << endl;
    return 0;
}
