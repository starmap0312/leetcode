/* - string("keyword") in set<string> s; ==> if (s.find("keyword") != s.end())
 * - "keyword" in string str; ==> if (str.find("keyword") != string::npos)
 * - convert set<string> s to vector<string> ==> vector<string> v(s.begin(), s.end());
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> results;
        for(int i = 0; i <= (int) s.size() - 10; i++) {
            string substring = s.substr(i, 10);
            if (results.find(substring) != results.end()) continue;
            if ((s.substr(i + 1)).find(substring) != string::npos) {
                results.insert(substring);
            }
        }
        return vector<string>(results.begin(), results.end());
    }
};

int main() {
    Solution solution;
    vector<string> results = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(vector<string>::iterator itr = results.begin(); itr != results.end(); itr++)
        cout << *itr << endl;
    return 0;
}
