/* - notice that all the words in the word list is of identical length
 * - solve the problem using hashmap
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) return result;
        int wordNum = words.size(), wordSize = words[0].size();
        for (int offset = 0; offset < wordSize; offset++) {
            unordered_map<string, int> dict = createMap(words);
            int count = dict.size();
            for (int i = offset; i + wordSize <= s.size(); i += wordSize) {
                string cur = s.substr(i, wordSize);
                if (dict.find(cur) != dict.end()) {
                    dict[cur]--;
                    if (dict[cur] == 0) count--;
                }
                if (i / wordSize >= wordNum) {
                    string prev = s.substr(i - wordNum * wordSize, wordSize);
                    if (dict.find(prev) != dict.end()) {
                        if (dict[prev] == 0) count++;
                        dict[prev]++;
                    }
                }
                if (count == 0) {
                    result.push_back(i - wordSize * (wordNum - 1));
                }
            }
        }
        return result;
    }

    unordered_map<string, int> createMap(vector<string>& words) {
        unordered_map<string, int> result;
        for (int i = 0; i < words.size(); i++) {
            result[words[i]]++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("bar"), words.push_back("foo");
    vector<int> positions = solution.findSubstring(s, words);
    for (int i = 0; i < positions.size(); i++) cout << positions[i] << " ";
    cout << endl;
    return 0;
}
