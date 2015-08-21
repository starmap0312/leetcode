/* - apply the KMP algorithm to improve the time, given string s the problem can be resovled by 
 *   computing the values of failure function for string (s + "#" + reverse_of_s)
 * - failure function: the length of the longest suffix of such that it's also a prefix
 *   ex.      0123456789
 *       p = "accadaccac"
 *       compute failure[9]:
 *       first, check failure[9 - 1] = len("acca") and check if p[4] == p[9] ('d' != 'c')
 *       next, check failure[4 - 1] = len("a") and check if p[1] == p[9] ('c' == 'c')
 *       because p[1] = p[9], we have that failure[9] = failure[4 - 1] + 1 = 2 = len("ac")
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string l = s + "#" + r;
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = j + (l[i] == l[j]);
        }
        return r.substr(0, s.size() - p.back()) + s;
    }
};

int main() {
    Solution solution;
    cout << solution.shortestPalindrome("aacecaaa") << endl;
    cout << solution.shortestPalindrome("abcd") << endl;
    cout << solution.shortestPalindrome("abbacd") << endl;
    return 0;
}
