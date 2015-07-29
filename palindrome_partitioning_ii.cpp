/* - vector<int> v; ==> vector<int> v(5, 0) to initialize vector v as a vector of 5 zeros
 * - precompute for all substrings (i, j) to see if s[i...j] are palindromes
 *   this utilizes incremental computing, as s[i...j] is palindrome if and only if s[i + 1...j - 1]
 *   is palindrome and s[i] == s[j]
 * - the pre-computation costs O(N^2) time, whereas if there is no pre-computation then deciding
 *   if s[i...j] is palindrome requires O(N) time, and there are O(N^2) possible queries, so the
 *   total time would be O(N^3)
 * - vector<vector<int> > v; ==> vector<vector<int> > v(3, vector<int>(6, 0)) to initialize a
 *                               two-dimentional vector (3 x 6 array)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) return 0;
        else { 
            vector<vector<bool> > isPalindromes = computePalindromes(s);
            vector<int> prev(s.size(), 0);
            for (int i = 0; i < s.size(); i++) {
                int minimun = s.size();
                for (int j = 0; j <= i; j++) {
                    if (j > 0 && prev[j - 1] >= minimun - 1) continue;
                    if (isPalindromes[j][i]) {
                        if (j == 0) { minimun = 0; break; }
                        else minimun = min(minimun, prev[j - 1] + 1);
                    }
                }
                prev[i] = minimun;
            }
            return prev[s.size() - 1];
        }
    }

    vector<vector<bool> > computePalindromes(const string &s) {
        // use DP to compute for all substrings to determine if they are palindromes
        vector<vector<bool> > result(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            result[i][i] = true;
            if (i > 0) result[i - 1][i] = (s[i - 1] == s[i]);
        }
        for (int l = 2; l < s.size(); l++)
            for (int i = l; i < s.size(); i++) {
                result[i - l][i] = (result[i - l + 1][i - 1] && s[i - l] == s[i]);
            }
        return result;
    }

    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.minCut("efe") << endl;
    return 0;
}
