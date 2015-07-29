#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        set<char> symbols;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                if (symbols.find(t[i]) == symbols.end()) {
                    mp[s[i]] = t[i];
                    symbols.insert(t[i]);
                } else return false;
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isIsomorphic("egg", "add") << endl;
    cout << solution.isIsomorphic("foo", "bar") << endl;
    return 0;
}
