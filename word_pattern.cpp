/* - use map<string, char> and set<char> to make sure that the one-to-one corresponding exist
 *   between each symbol of the pattern and each word of the string
 * - to tokenize a string with space separator, use the following loop:
 *   ex. while (pos != string:npos) {
 *           int nextPos = str.find(' ', pos) + 1;
 *           string word;
 *           if (nextPos == string::npos) {
 *               word = str.substr(pos);
 *               pos = nextPos;
 *           } else {
 *               word = str.substr(pos, nextPos - pos);
 *               pos = nextPos + 1;
 *           }
 *       }
 */
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() != 0 && str.size() == 0) return false;
        if (pattern.size() == 0 && str.size() != 0) return false;
        map<string, char> dict;
        set<char> symbols;
        int pos = 0, index = 0;
        while (index < pattern.size() && pos != string::npos) {
            string word = nextWord(str, pos);
            if ((dict.find(word) != dict.end() && dict[word] != pattern[index]) ||
                (dict.find(word) == dict.end() && symbols.find(pattern[index]) != symbols.end()))
                return false;
            if (dict.find(word) == dict.end() && symbols.find(pattern[index]) == symbols.end()) {
                dict[word] = pattern[index]; 
                symbols.insert(pattern[index]);
            }
            index++;
        }
        if (pos != string::npos || index != pattern.size())
            return false;
        return true;
    }

    string nextWord(string &str, int &pos) {
        int nextPos = str.find(' ', pos);
        string word;
        if (nextPos == string::npos) {
            word = str.substr(pos);
            pos = nextPos;
        } else {
            word = str.substr(pos, nextPos - pos);
            pos = nextPos + 1;
        }
        return word;
    }
};

int main() {
    Solution solution;
    cout << solution.wordPattern("abba", "dog cat cat dog") << endl;
    cout << solution.wordPattern("abba", "dog cat cat fish") << endl;
    return 0;
}
