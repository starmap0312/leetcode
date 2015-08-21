/* - solved by dynamic programming (using straightforward recursion takes long time)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() < 1 || s == "0") return 0;
        vector<int> ans(s.size());
        ans[0] = (s[0] == '0'? 0: 1);
        for (int i = 1; i < s.size(); i++) {
            if ((s[i - 1] == '1' && s[i] >= '1' && s[i] <= '9') || 
                (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                ans[i] = (i >= 2? ans[i - 2] + ans[i - 1]: ans[i - 1] + 1);
            } else if ((s[i - 1] == '1' || s[i - 1] == '2') && s[i] == '0')
                ans[i] = (i >= 2? ans[i - 2]: 1);
            else if (s[i] == '0') return 0;
            else
                ans[i] = ans[i - 1];
        }
        return ans.back();
    }
};

int main() {
    Solution solution;
    cout << solution.numDecodings("12") << endl;
    return 0;
}
