/* - set<int> s1, s2; ==> use (s1 == s2) to compare if two sets contain identical elements
 * - map<char, int> m1, m2; ==> use (m1 == m2) to compare if two maps are identical
 * - to solve the problem, for each j < s.size() find the shortest substring ending at j that 
 *   contains all characters of string t
 *   maintain two pointers i and j: 
 *   for each candidate substring ending at j, try to increment i so that substring s[i..j] contains
 *   all characters of t
 *   for the next ending position j + 1, the algorithm continues from the substring s[i..j + 1] and
 *   need not to examine from i = 0, i.e. substring s[0..j + 1]
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp, target = alphabet(t);
        int minLength = s.size() + 1, index = -1;
        int i = 0, j = 0;
        while (j < s.size()) {
            if (target.find(s[j]) != target.end()) // if target contains [s[j]]
                mp[s[j]]++;
            while (contains(mp, target)) {
                if (j - i + 1 < minLength) {
                    index = i;
                    minLength = j - i + 1;
                }
                if (target.find(s[i]) != target.end()) { // if target contains s[i]
                    mp[s[i]]--;
                }
                i++;
            }
            j++;
        }
        if (index == -1) return "";
        return s.substr(index, minLength);
    }

    bool contains(unordered_map<char, int> &mp, unordered_map<char, int> &target) {
        for (unordered_map<char, int>::iterator itr = target.begin(); itr != target.end(); itr++) {
            if (mp[itr -> first] < itr -> second) return false;
        }
        return true;
    }

    unordered_map<char, int> alphabet(string &s) {
        unordered_map<char, int> result;
        for (int i = 0; i < s.size(); i++)
            result[s[i]]++;
        return result;
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution solution;
    cout << solution.minWindow(s, t) << endl;
    return 0;
}
