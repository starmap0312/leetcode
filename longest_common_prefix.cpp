#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int length = INT_MAX;
        for (int i = 0; i < strs.size() - 1; i++) {
            length = LCE(strs[i], strs[i + 1], length);
        }
        return strs[0].substr(0, length);
    }
    int LCE(string &s1, string &s2, int length) {
        int i;
        for (i = 0; i < s1.size() && i < s2.size() && i < length; i++)
            if (s1[i] != s2[i]) break;
        return i;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("aab");
    strs.push_back("ab");
    strs.push_back("abc");
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
