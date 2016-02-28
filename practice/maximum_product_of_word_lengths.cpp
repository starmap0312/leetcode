/* - preprocessing for the alphabets of the input strings is important, as it avoids the
 *   redundant work and is efficient in time
 * - bypass iterations where the product already shows not it is not large enough to update
 *   the value of max product
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = INT_MIN; // storing the max product
        vector<set<char> > alphabets;
        for (int i = 0; i < words.size(); i++) {
            alphabets.push_back(findAlphabet(words[i]));
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int product = words[i].size() * words[j].size();
                if (product <= result) continue; // bypass for efficiency
                if (!intersect(alphabets[i], alphabets[j]) && product > result) {
                    result = product;
                }
            }
        }
        return (result == INT_MIN? 0: result);
    }

    bool intersect(set<char> &s1, set<char> &s2) {
        /* one can use C++ STD algorithm: set_intersection() to find the intersection of two sets
         * however, the algorithm actually computes the intersection, unlike our implementation
         * that immediately returns if an common element is found; therefore, it is not faster
         * than our approach
         * set<char> intersection;
         * set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
         *     std::inserter(intersection, intersection.begin()));
         * return !intersection.empty();
         */
        for (set<char>::iterator itr = s1.begin(); itr != s1.end(); itr++) {
            if (s2.find(*itr) != s2.end()) return true;
        }
        return false;
    }

    set<char> findAlphabet(string &word) {
        set<char> result;
        for (int i = 0; i < word.size(); i++) {
            result.insert(word[i]);
        }
        return result;
    }
};

int main() {
    string a[] = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    vector<string> words(a, a + 6);
    Solution solution;
    cout << solution.maxProduct(words) << endl;
    return 0;
}
