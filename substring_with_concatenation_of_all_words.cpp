#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            vector<int> pos = findWord(s, words[i]);
            vector<string> new_words = words;
            new_words.erase(new_words.begin() + i);
            for (int j = 0; j < pos.size(); j++) {
                if (match(s, pos[j] + words[i].size(), new_words)) { result.push_back(pos[j]); }
            }
        }
        return result;
    }

    vector<int> findWord(string &s, string &word) {
        vector<int> result;
        int pos = -1;
        while (true) {
            pos = s.find(word, pos + 1);
            if (pos == string::npos) break;
            else result.push_back(pos);
        }
        return result;
    }

    bool match(string &s, int pos, vector<string> &words) {
        if (words.size() == 0) return true;
        for (int i = 0; i < words.size(); i++) {
            int size  = words[i].size();
            if (s.substr(pos, size) == words[i]) {
                vector<string> new_words = words;
                new_words.erase(new_words.begin() + i);
                if (match(s, pos + size, new_words)) return true;
            }
        }
        return false;
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
