#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[')'] = '(', mp[']'] = '[', mp['}'] = '{';
        stack<char> symbols;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                symbols.push(s[i]);
            else {
                if (symbols.size() > 0 && symbols.top() == mp[s[i]]) symbols.pop();
                else return false;
            }
        }
        if (symbols.size() == 0) return true;
        else return false;
    }
};

int main() {
    string s = "()[]{([)]}";
    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}
