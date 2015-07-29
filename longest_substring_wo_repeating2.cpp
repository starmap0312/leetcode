/* - map<char, int> dict;
 * - dict[key] = value ==> add if key not in dict, and override if key in dict
 *   dict[key]         ==> if key not in dict, accessing dict[key] will set dict[key] = 0
 * - key not in dict ==> dict.find(key) == dict.end() 
 *                       dict.count(key) == 0
 * - min/max functions ==> min(num1, num2) and max(num1, num2)
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s) {
    map<char, int> locations;
    int max_prefix_length = 0, max_length = 0;
    for(int i = 0; i < s.size(); i++) {
        if(locations.find(s[i]) == locations.end()) {
            max_prefix_length++;
        } else {
            int length = i - locations[s[i]];
            max_prefix_length = min(length, max_prefix_length + 1);
        }
        locations[s[i]] = i;
        max_length = max(max_prefix_length, max_length);
    }
    return max_length;
}

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
