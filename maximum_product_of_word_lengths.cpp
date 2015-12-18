#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<set<char> > symbols;
        for (int i = 0; i < words.size(); i++) {
            symbols.push_back(getSymbols(words[i]));
        }
        int maxProduct = INT_MIN;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!intersect(symbols[i], symbols[j])) {
                    int product = words[i].size() * words[j].size();
                    if (maxProduct < product) {
                        maxProduct = product;
                    }
                }
            }
        }
        return ((maxProduct == INT_MIN)? 0: maxProduct);
    }

    set<char> getSymbols(string &word) {
        set<char> result;
        for (int i = 0; i < word.size(); i++)
            result.insert(word[i]);
        return result;
    }

    bool intersect(set<char> &s1, set<char> &s2) {
        for (set<char>::iterator itr = s1.begin(); itr != s1.end(); itr++)
            if (s2.find(*itr) != s2.end()) return true;
        return false;
    }
};

int main() {
    string a[] = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    vector<string> words(a, a + 6);
    Solution solution;
    cout << solution.maxProduct(words) << endl;
    return 0;
}
