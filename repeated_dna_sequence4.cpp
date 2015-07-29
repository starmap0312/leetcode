/* - holding all length-10 substring occurrences in a set uses a lot of memory, use 1-to-1 mapping
 *   to an integer hash value instead reduces the memory usage
 *   hold length-10 substrings: 10-bytes keys == 80-bits keys vs. hold integer hashes: 32-bits keys
 *   this reduces the memory to at least a half
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> results;
        for(int i = 0; i <= (int) s.size() - 10; i++) {
            if (dict.find(encode(s.substr(i, 10))) == dict.end()) 
                dict.insert(encode(s.substr(i, 10)));
            else
                dna.insert(s.substr(i, 10));
        }
        for(set<string>::iterator itr = dna.begin(); itr != dna.end(); itr++) {
            results.push_back(*itr);
        }
        return results;
    }
private:
    int encode(string s) {
        int hash = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') hash = hash * 4;
            else if (s[i] == 'T') hash = hash * 4 + 1;
            else if (s[i] == 'C') hash = hash * 4 + 2;
            else hash = hash * 4 + 3;
        }
        return hash;
    }
    set<int> dict;
    set<string> dna;
};

int main() {
    Solution solution;
    vector<string> results = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(vector<string>::iterator itr = results.begin(); itr != results.end(); itr++)
        cout << *itr << endl;
    return 0;
}
