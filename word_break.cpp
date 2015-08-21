/* - a recursive approach which takes long time
 * - try to improve the time by using dynamic programming
 */
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return solve(s, wordDict, 0);
    }
    bool solve(string &s, unordered_set<string>& wordDict, int offset) { 
        if (offset == s.size()) return true;
        for (unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); itr++) {
            cout << *itr << endl;
            if (s.find(*itr, offset) == offset) {
                wordDict.erase(*itr);
                if (solve(s, wordDict, offset + (*itr).size())) return true;
                wordDict.insert(*itr);
            }
        }
        return false;
    }
};

int main() {
    /*
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string dict[] = {
        "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
        };
    */
    unordered_set<string> wordDict;
    string s = "aaaaaa";
    wordDict.insert("aaaa"), wordDict.insert("aa");
    /*
    for (int i = 0; i < 10; i++)
        wordDict.insert(dict[i]);
    */
    Solution solution;
    cout << solution.wordBreak(s, wordDict) << endl;
    return 0;
}
