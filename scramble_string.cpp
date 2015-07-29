/* - string s; ==> s.substr(2, 2) returns a copy of substring s[2...3]
 * - use recursion to solve the problem: s1 and s2 are scramble strings if and only if
 *   for some i = 1...n - 1
 *       partition s1[0...i - 1], s1[i...n - 1] maps to partition s2[0...i - 1], s2[i...n - 1]
 *       and these substrings are recursively scramble
 *       OR
 *       partition s1[0...i - 1], s1[i...n - 1] maps to partition s2[0...n-i-1], s2[n - i...n - 1]
 *       and these substrings are recursively scramble
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() <= 2 && sameChar(s1, s2)) return true;
        else if (s1.size() <= 2 && !sameChar(s1, s2)) return false;
        for (int i = 1; i < s1.size(); i++) {
            string s1_prefix = s1.substr(0, i), s1_suffix = s1.substr(i);
            string s2_prefix1 = s2.substr(0, i), s2_suffix1 = s2.substr(i);
            string s2_prefix2 = s2.substr(s1.size() - i), s2_suffix2 = s2.substr(0, s1.size() - i);
            if (sameChar(s1_prefix, s2_prefix1) && sameChar(s1_suffix, s2_suffix1) &&
                isScramble(s1_prefix, s2_prefix1) && isScramble(s1_suffix, s2_suffix1))
                return true;
            else if (sameChar(s1_prefix, s2_prefix2) && sameChar(s1_suffix, s2_suffix2) &&
                isScramble(s1_prefix, s2_prefix2) && isScramble(s1_suffix, s2_suffix2))
                return true;
        }
        return false;
    }

    bool sameChar(string s1, string s2) {
        if (s1.size() == 0) return true;
        unordered_map<char, int> mp;
        for (int i = 0; i < s1.size(); i++)
            mp[s1[i]]++;
        for (int i = 0; i < s2.size(); i++) {
            mp[s2[i]]--;
            if (mp[s2[i]] < 0) return false;
        }
        return true;
    }
};

int main() {
    string s1 = "great", s2 = "rgtae";
    Solution solution;
    cout << solution.isScramble(s1, s2) << endl;
    return 0;
}
