/* - the problem can be solved by dynamic programming. the recursion is as follows:
 *   if we know the answers of (s1[0..i - 1], s2[0..j], s3[0..i + j]), denoted by ans[i][j + 1]
 *                             (s1[0..i], s2[0..j - 1], s3[0..i + j]), denoted by ans[i + 1][j]
 *   the answer of (s1[0..i], s2[0..j], s3[0..i + j + 1]), denoted by ans[i + 1][j + 1] can be 
 *   obtained
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > ans(s1.size() + 1, vector<bool>(s2.size() + 1));
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) ans[i][j] = true;
                else if (i == 0) {
                    ans[i][j] = (s2[j - 1] == s3[i + j - 1]? ans[i][j - 1]: false);
                } else if (j == 0) {
                    ans[i][j] = (s1[i - 1] == s3[i + j - 1]? ans[i - 1][j]: false);
                } else {
                    ans[i][j] = (s1[i - 1] == s3[i + j - 1]? ans[i - 1][j]: false) || 
                                (s2[j - 1] == s3[i + j - 1]? ans[i][j - 1]: false);
                }
            }
        }
        return ans[s1.size()][s2.size()];
    }
};

int main() {
    Solution solution;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << solution.isInterleave(s1, s2, s3) << endl;
    return 0;
}
