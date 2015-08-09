#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        s = trimSpaces(s);
        if (s.size() == 0) return;
        reverse(s, 0, s.size() - 1);
        int pos = 0; 
        while (pos != string::npos) {
            int nextPos = s.find(' ', pos);
            if (nextPos == string::npos){
                reverse(s, pos, s.size() - 1);
                break;
            } else {
                reverse(s, pos, nextPos - 1);
                pos = nextPos + 1;
            }
        }
    }
    string trimSpaces(string &s) {
        string result = "";
        bool readSpace = false;
        for (int i = 0; i < s.size(); i++) {
           if (s[i] != ' ') {
               result += s[i];
               readSpace = false;
           } else if (!readSpace) {
               result += s[i];
               readSpace = true;
           }
        }
        if (result.size() > 0) {
            if (result[0] == ' ')
                result = result.substr(1);
        }
        if (result.size() > 0) {
            if (result[result.size() - 1] == ' ')
                result = result.substr(0, result.size() - 1);
        }
        return result;
    }
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};

int main() {
    Solution solution;
    string s = "the sky is blue";
    solution.reverseWords(s);
    cout << s << endl;
    return 0;
}
