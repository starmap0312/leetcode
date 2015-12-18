/* - this approach scans the string from right to left to identify the first character of
 *   the smallest lexicographical order string that contains no duplicate letters
 *   ex.  c  b  a  c  d  c  b  c  ==> input string
 *        -  -  -                 ==> characters 'c', 'b', 'a' could be the first character of 
 *                                    strings with no duplicate letters, as to their right there 
 *                                    exist all the other characters except themself
 *   as 'a' is of the smallest lexicographical order, the algorithm repeats the procedure for
 *   the suffix string after the position of character 'a'
 * - repeat the above procedure until the second, third, and fourth characters are identified
 *   ex.  c  b (a) c  d  c  b  c  ==> 'a' is picked and repeat for the suffix string after 'a'
 *                 -              ==> character 'c' is the only candidate of the second character
 *                                    as the other characters 'b' and 'd' are to its right
 *        c  b (a)(c) d  c  b  c  ==> 'c' is picked and repeat for the suffix string after 'c'
 *                    -  x     x  ==> character 'd' is the only candidate of the third character
 *                                    as the other characters 'b' is to its right
 *        c  b (a)(c)(d) c  b  c  ==> 'd' is picked and repeat for the suffix string after 'd'
 *                       x  -  x  ==> character 'b' is the only candidate of the fourth character
 *        c  b (a)(c)(d) c (b) c  ==> 'b' is picked and terminate the procedure
 *   output string "acdb" as the answer
 * - the total time required is O(n * k), where is the number of distinct characters
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        unordered_set<char> alphabet;
        for (int i = 0; i < s.size(); i++) {
            alphabet.insert(s[i]);
        }
        int start = 0;
        while (!alphabet.empty()) {
            unordered_map<char, int> indices;
            unordered_set<char> symbols;
            for (int i = s.size() - 1; i >= start; i--) {
                if (alphabet.find(s[i]) != alphabet.end()) {
                    symbols.insert(s[i]);
                    if (symbols.size() == alphabet.size()) {
                        indices[s[i]] = i;
                    }
                }
            }
            int index = -1;
            for (unordered_map<char, int>::iterator itr = indices.begin();
                itr != indices.end(); itr++) {
                if (index == -1 || itr -> first < s[index]) {
                    index = itr -> second;
                }
            }
            alphabet.erase(s[index]);
            result += s[index];
            start = index + 1;
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
