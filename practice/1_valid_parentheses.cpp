/* - the problem can be solved using stack 
 */
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> symbols;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                symbols.push(s[i]);
            else {
                if (symbols.size() > 0) symbols.pop();
                else return false;
            }
        }
        if (symbols.size() == 0) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    string valid = "()(())";
    cout << solution.isValid(valid) << endl;
    string invalid = "()(()";
    cout << solution.isValid(invalid) << endl;
    return 0;
}
