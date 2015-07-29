/* - string s; ==> sort(s.begin(), s.end()) will sort the characters of string s 
 * - when branching a tree based on some condition, consider to branch to the next level first
 *   check the condition in the next level, and immediately return if the condition is satified
 *   this may simplify the code and increases the readability
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (!sameChar(s1, s2)) return false;
        if (s1.size() <= 2) return true;
        for (int i = 1; i < s1.size(); i++) {
            string s1_prefix = s1.substr(0, i), s1_suffix = s1.substr(i);
            string s2_prefix1 = s2.substr(0, i), s2_suffix1 = s2.substr(i);
            string s2_prefix2 = s2.substr(s1.size() - i), s2_suffix2 = s2.substr(0, s1.size() - i);
            if ((isScramble(s1_prefix, s2_prefix1) && isScramble(s1_suffix, s2_suffix1)) ||
                (isScramble(s1_prefix, s2_prefix2) && isScramble(s1_suffix, s2_suffix2)))
                return true;
        }
        return false;
    }

    bool sameChar(string s1, string s2) {
        if (s1.size() == 0) return true;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return (s1 == s2);
    }
};

int main() {
    string s1 = "great", s2 = "rgtae";
    Solution solution;
    cout << solution.isScramble(s1, s2) << endl;
    return 0;
}
