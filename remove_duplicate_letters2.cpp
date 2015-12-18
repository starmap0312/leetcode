/* - the algorithm also identifies the first, second, ..., until the last characters one by one, 
 *   but with a different approach:
 *   scan the string from left to right and uses a hashmap to record the number of occurrences of
 *   each symbol in the suffix string
 * - at some point during the scan, if the occurrence of some symbol in the suffix string does
 *   not exist, then the first character is determined
 *   ex.  c  b  a  c  d  c  b  c  ==> input string
 *        -                           mp['a'] = 1, mp['b'] = 2, mp['c'] = 4, mp['d'] = 1
 *                 -                  mp['a'] = 0, mp['b'] = 1, mp['c'] = 3, mp['d'] = 1
 *   according to the hashmap, the symbol 'a' does not exist in the suffix string "cdcbc"
 *   therefore, the first character can be determined, which is the one with the smallest
 *   lexicographical order, i.e. 'a'
 * - remove the prefix and also symbol 'a' in the suffix string, and repeat the procedure
 *   ex.  c  d  c  b  c           ==> the suffix string after removal
 *        -                           mp['b'] = 1, mp['c'] = 3, mp['d'] = 1
 *           -                        mp['b'] = 1, mp['c'] = 2, mp['d'] = 1
 *              -                     mp['b'] = 1, mp['c'] = 2, mp['d'] = 0
 *   according to the hashmap, the symbol 'd' does not exist in the suffix string "cbc"
 *   therefore, the second character can be determined, which is the one with the smallest
 *   lexicographical order, i.e. 'c'
 *   ex.  d  b                    ==> the suffix string after removal
 *        -                           mp['b'] = 1, mp['d'] = 1
 *           -                        mp['b'] = 1, mp['d'] = 0
 *   according to the hashmap, the symbol 'd' does not exist in the suffix string "b"
 *   therefore, the third character can be determined, which is the one with the smallest
 *   lexicographical order, i.e. 'd'
 *   ex.  b                       ==> the suffix string after removal
 *        -                           mp['b'] = 1
 *           -                        mp['b'] = 0
 *   according to the hashmap, the symbol 'b' does not exist in the suffix string ""
 *   therefore, the fourth character can be determined, which is the one with the smallest
 *   lexicographical order, i.e. 'b'
 * - terminate the procedure and output "acdb" as the answer
 * - the time required is O(n * k), where k is the number of distinct symbols
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        while (s.size() > 0) {
            unordered_map<char, int> count;
            for (int i = 0; i < s.size(); i++) {
                count[s[i]]++;
            }
            int index = -1;
            for (int i = 0; i < s.size(); i++) {
                if (index == -1 || s[i] < s[index]) {
                    index = i;
                }
                count[s[i]]--;
                if (count[s[i]] == 0) break;
            }
            result += s[index];
            string next = "";
            for (int i = index + 1; i < s.size(); i++)
                if (s[i] != s[index]) next += s[i];
            s = next;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.removeDuplicateLetters("bcabc") << endl;
    cout << solution.removeDuplicateLetters("cbacdcbc") << endl;
    return 0;
}
