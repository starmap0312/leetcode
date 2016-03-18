/* - use dynamic programming to solve the problem efficiently
 *   let answers[i][j] denote if text[0..i] and pattern[0..j] matches
 *   we have that
 *   if pattern[j] == '*', pattern[0..j - 1] can be matched with any text[0..i'], where i' <= i
 *   if pattern[j] == '?', answers[i][j] = answers[i - 1][j - 1]
 * - allocate and use a two-dimensional array is slightly faster than vector<vector<TYPE> >
 *   ex. int **arr = new int[10][20];  ==> Compile Error !!! 
 *       instead, think of:
 *       int *arr0 = new int[20];
 *       int *arr1 = new int[20];
 *       ...
 *       so, define and allocate as follows:
 *       int **arr = new int*[10];     ==> we need an array of integer pointers
 *       for (int i = 0; i < 10; i++)
 *           arr[i] = new int[20];     ==> for each pointer, allocate an integer array
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool **answers = new bool*[s.size() + 1];
        for (int i = 0; i <= s.size(); i++)
            answers[i] = new bool[p.size() + 1];
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= p.size(); j++) {
                if (i == 0 && j == 0) answers[i][j] = true;
                else if (i == 0) {
                    if (p[j - 1] == '*') answers[i][j] = answers[i][j - 1];
                    else answers[i][j] = false;
                } else if (j == 0) {
                    answers[i][0] = false;
                } else {
                    if (p[j - 1] == '?') {
                        answers[i][j] = answers[i - 1][j - 1];
                    } else if (p[j - 1] == '*') {
                        if (j >= 2 && p[j - 2] == '*') {
                            answers[i][j] = answers[i][j - 1];
                        } else {
                            answers[i][j] = false;
                            for (int k = i; k >= 0 && !answers[i][j]; k--)
                                answers[i][j] = (answers[i][j] || answers[k][j - 1]);
                        }
                    } else {
                        answers[i][j] = ((s[i - 1] == p[j - 1]) && answers[i - 1][j - 1]);
                    }
                }
            }
        }
        return answers[s.size()][p.size()];
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "*") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("aa", "?*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    return 0;
}
