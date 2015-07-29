/* - set<int> s; ==> insert integer by calling s.insert(num)
 * - map<string, int>::iterator itr ==> (key, value) = (itr -> first, itr -> second)
 * - string s; ==> s.size() returns unsigned int, so it cannot be negative
 * - map<string, int> dict; ==> if "abc" not in dict, access dict["abc"] will set dict["abc"] = 0
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> results;
        for(int i = 0; i <= (int) s.size() - 10; i++) {
            dict[s.substr(i, 10)]++;
            //if (dict.find(s.substr(i, 10)) == dict.end()) dict[s.substr(i, 10)] = 1;
            //else dict[s.substr(i, 10)]++;
        }
        for(map<string, int>::iterator itr = dict.begin(); itr != dict.end(); itr++) {
            if (itr -> second > 1) results.insert(itr -> first);
        }
        return vector<string>(results.begin(), results.end());
    }
private:
    map<string, int> dict;
};

int main() {
    Solution solution;
    vector<string> results = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(vector<string>::iterator itr = results.begin(); itr != results.end(); itr++)
        cout << *itr << endl;
    return 0;
}
