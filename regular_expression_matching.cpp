/* - use dynamic programming to solve the problem efficiently
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pair<char, char> > pattern = parse(p);
        vector<vector<bool> > answers(s.size() + 1, vector<bool>(pattern.size() + 1));
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= pattern.size(); j++) {
                if (i == 0 && j == 0) {
                    answers[i][j] = true;
                } else if (i == 0 && j > 0) {
                    if (pattern[j - 1].second == '*')
                        answers[i][j] = answers[i][j - 1];
                    else
                        answers[i][j] = false;
                } else if (i > 0 && j == 0) {
                    answers[i][j] = false;
                } else {
                    if (pattern[j - 1].second != '*') {
                        if (pattern[j - 1].first == '.')
                            answers[i][j] = answers[i - 1][j - 1];
                        else
                            answers[i][j] = ((s[i - 1] == pattern[j - 1].first) && 
                                             answers[i - 1][j - 1]);
                    } else {
                        answers[i][j] = false;
                        for (int k = i; k >= 0 && !answers[i][j]; k--) {
                            if (k < i && pattern[j - 1].first != '.' && 
                                pattern[j - 1].first != s[k])
                                break;
                            if (answers[k][j - 1]) answers[i][j] = true;
                        }
                    }
                }
            }
        }
        return answers[s.size()][pattern.size()];
    }

    vector<pair<char, char> > parse(string &p) {
        vector<pair<char, char> > result;
        for (int j = 0; j < p.size(); j++) {
            if (j + 1 < p.size() && p[j + 1] == '*')
                result.push_back(make_pair(p[j++], '*'));
            else
                result.push_back(make_pair(p[j], ' '));
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("aa", ".*") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    return 0;
}
