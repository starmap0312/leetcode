/* - a trie supports operations such as insert(word), search(word), startsWith(prefix) 
 */
#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isWordEnd = false;
    }
    TrieNode *children[26]; // each node of the trie can have 26 children
    bool isWordEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (itr -> children[index] == NULL)
                itr -> children[index] = new TrieNode();
            itr = itr -> children[index];
        }
        itr -> isWordEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (itr -> children[index] == NULL) return false;
            itr = itr -> children[index];
        }
        return itr -> isWordEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *itr = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (itr -> children[index] == NULL) return false;
            itr = itr -> children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    // Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("somestring");
    cout << trie.search("key") << endl;
    cout << trie.search("somestring") << endl;
    return 0;
}
