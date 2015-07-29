/* - map<string, int> dict; ==> use (dict.count("key") > 0 ?) to check if "key" is in the mapping
 *                              use dict.clear() to remove all elements, so that dict.size() == 0
 * - set<string> pool;      ==> use (pool.count("key") > 0 ?) to check if "key" is in the set
 *                              use pool.clear() to remove all elements, so that pool.size() == 0
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) {
            return result;
        }
        
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) == hash.end()) {
                hash[words[i]] = 1;
            } else {
                hash[words[i]]++;
            }
        }
        
        int wSize = words[0].length();
        for (int start = 0; start < wSize; start++) {
            int wCount = 0;
            unordered_map<string, int> slidingWindow;
            for (int i = start; i + wSize <= s.length(); i+=wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {
                    slidingWindow.clear();
                    wCount = 0;
                } else {
                    if (wCount == words.size()) {
                        string removedWord = s.substr(i - wCount * wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                    wCount++;
                    if (slidingWindow.find(word) == slidingWindow.end()) {
                        slidingWindow[word] = 1;
                    } else {
                        slidingWindow[word]++;
                    }
                    while (hash[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i - (wCount-1) * wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                }
                
                if (wCount == words.size()) {
                    result.push_back(i - (wCount - 1) * wSize);
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    cout << s << endl;
    vector<string> words;
    words.push_back("bar"), words.push_back("foo");
    vector<int> positions = solution.findSubstring(s, words);
    for (int i = 0; i < positions.size(); i++) cout << positions[i] << " ";
    cout << endl;
    return 0;
}
