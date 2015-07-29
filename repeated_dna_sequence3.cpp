/* 
 * 
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Node {
public:
    Node() {
        for(int i = 0; i < 4; i++) children[i] = NULL;
    } 
    Node *children[4]; // A, T, C, G
};

class Trie {
public:
    Trie() {
        root = new Node;
        toIndex['A'] = 0, toIndex['T'] = 1, toIndex['C'] = 2, toIndex['G'] = 3;
    }
    bool addString(string s) {
        Node *ptr = root;
        for(int i = 0; i < s.size(); i++) {
            int index = toIndex[s[i]];
            if (i == s.size() - 1 && ptr -> children[index] != NULL) return true;
            if (ptr -> children[index] == NULL) ptr -> children[index] = new Node;
            ptr = ptr -> children[index];
        }
        return false;
    }
private:
    map<char, int> toIndex;
    Node* root;
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> results;
        for(int i = 0; i <= (int) s.size() - 10; i++) {
            if (trie.addString(s.substr(i, 10))) results.insert(s.substr(i, 10));
        }
        return vector<string>(results.begin(), results.end());
    }
private:
    Trie trie;
};

int main() {
    Solution solution;
    vector<string> results = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(vector<string>::iterator itr = results.begin(); itr != results.end(); itr++)
        cout << *itr << endl;
    return 0;
}
