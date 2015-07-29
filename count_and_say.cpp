#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string s = "1", next_s = "";
        for (int i = 0; i < n - 1; i++) {
            next_s = "";
            int start = 0, end = 0;
            while (start < s.size() && end + 1 < s.size()) {
                if (s[end] == s[end + 1]) end++;
                else { 
                    next_s += (char)('0' + (end - start + 1));
                    next_s += s[start];
                    start = end + 1, end = end + 1;
                }
            }
            next_s += (char)('0' + (end - start + 1));
            next_s += s[start];
            s = next_s;
        }
        return s;
    }
};

int main() {
    Solution solution;
    cout << solution.countAndSay(4) << endl;
    return 0;
}
