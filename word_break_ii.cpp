#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (!checkAlphabet(s, wordDict) || !checkEnd(s, wordDict))
            return solutions;
        vector<string> solution;
        findSolution(s, 0, wordDict, solution);
        return solutions;
    }

    bool checkEnd(string &s, unordered_set<string>& wordDict) {
        for (unordered_set<string>::iterator itr = wordDict.begin();
            itr != wordDict.end(); itr++) {
            int size = (*itr).size();
            if (s.size() >= size && s.substr(s.size() - size, size) == *itr)
                return true;
        }
        return false;
    }

    bool checkAlphabet(string &s, unordered_set<string>& wordDict) {
        unordered_set<char> alphabet;
        for (unordered_set<string>::iterator itr = wordDict.begin();
            itr != wordDict.end(); itr++) {
            unordered_set<char> rc = findAlphabet(*itr);
            alphabet.insert(rc.begin(), rc.end());
        }
        for (int i = 0; i < s.size(); i++) {
            if (alphabet.find(s[i]) == alphabet.end())
                return false;
        }
        return true;
    }

    void findSolution(string &s, int offset, unordered_set<string> &wordDict, 
        vector<string> &solution) {
        if (offset == s.size()) {
            string s = "";
            for (int i = 0; i < solution.size() - 1; i++)
                s += solution[i] + " ";
            s += solution[solution.size() - 1];
            solutions.push_back(s);
        }
        for (unordered_set<string>::iterator itr = wordDict.begin();
            itr != wordDict.end(); itr++) {
            int size = (*itr).size();
            if (s.substr(offset, size) == *itr) {
                solution.push_back(*itr);
                findSolution(s, offset + size, wordDict, solution);
                solution.pop_back();
            }
        }
    }

    unordered_set<char> findAlphabet(string s) {
        unordered_set<char> result;
        for (int i = 0; i < s.size(); i++)
            result.insert(s[i]);
        return result;
    }

private:
    vector<string> solutions;
};

int main() {
    string s = "catsanddog";
    unordered_set<string> wordDict;
    string a[] = { "cat", "cats", "and", "sand", "dog" };
    for (int i = 0; i < 5; i++)
        wordDict.insert(a[i]);
    Solution solution;
    vector<string> rc = solution.wordBreak(s, wordDict);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
