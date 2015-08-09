/* - sort each of the input strings, find the set of sorted strings of anagrams
 *   use that set of sorted strings to identify all anagrams
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        vector<string> sorted = strs;
        for (int i = 0; i < sorted.size(); i++) {
            sort(sorted[i].begin(), sorted[i].end());
        }
        sort(sorted.begin(), sorted.end());
        set<string> dup;
        string last = "";
        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i - 1] == sorted[i] && (last == "" || last != sorted[i])) {
                dup.insert(sorted[i]);
                last = sorted[i];
            }
        }
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (dup.find(s) != dup.end()) result.push_back(strs[i]);
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("angel"), strs.push_back("angle");
    strs.push_back("bad"), strs.push_back("dddd");
    Solution solution;
    vector<string> result = solution.anagrams(strs);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
