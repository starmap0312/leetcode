#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, start = -1, end = -1;
        for(i = s.size() - 1; i >= 0; i--) {
            if (end == -1 && s[i] == ' ') { }
            else if (end == -1 && s[i] != ' ') { start = end = i; }
            else if (s[i] == ' ') { break; }
            else start--;
        }
        if (start == -1 && end == -1) return 0;
        return (end - start + 1);
    }
};

int main() {
    Solution solution;
    string s = "Hello World";
    cout << solution.lengthOfLastWord(s) << endl;
    return 0;
}
