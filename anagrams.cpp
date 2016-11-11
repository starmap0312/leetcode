/* - first find the set of alphabet of all input strings, create a mapping from alphabet
 *   to number of duplication, use that mapping to find all anagrams
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        map<set<char>, int> mp;
        for (int i = 0; i < strs.size(); i++) {
            mp[alphabet(strs[i])]++;
        }
        for (int i = 0; i < strs.size(); i++) {
            if (mp[alphabet(strs[i])] > 0) {
                result.push_back(strs[i]);
            }
        }
        return result;
    }
    set<char> alphabet(string s) {
        set<char> result;
        for (int i = 0; i < s.size(); i++) {
            result.insert(s[i]);
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("angel"), strs.push_back("angle");
    Solution solution;
    vector<string> result = solution.anagrams(strs);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
