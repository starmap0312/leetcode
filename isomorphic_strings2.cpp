#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, unmp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end() && unmp.find(t[i]) == unmp.end()) {
                mp[s[i]] = t[i];
                unmp[t[i]] = s[i];
            } else {
                if (mp.find(s[i]) != mp.end() && mp[s[i]] != t[i])
                    return false;
                if (unmp.find(t[i]) != unmp.end() && unmp[t[i]] != s[i])
                    return false;
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
