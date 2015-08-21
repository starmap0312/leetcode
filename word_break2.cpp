/* - a dynamic programming approach: compute the answer for the prefix string s[0...i] using
 *   the answers of s[0...i'] for i' < i
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0) return false;
        vector<bool> answers(s.size(), false);
        for (int i = 0; i < answers.size(); i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                answers[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (answers[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
                    answers[i] = true;
                    break;
                }
            }
        }
        return answers.back();
    }
};

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string dict[] = {
        "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
        };
    unordered_set<string> wordDict;
    //string s = "aaaaaa";
    //wordDict.insert("aaaa"), wordDict.insert("aa");
    for (int i = 0; i < 10; i++)
        wordDict.insert(dict[i]);
    Solution solution;
    cout << solution.wordBreak(s, wordDict) << endl;
    return 0;
}
