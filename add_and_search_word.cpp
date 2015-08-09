#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    } 
    TrieNode *children[26];
    bool isWord;
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    void add(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = (int)(word[i] - 'a');
            if (itr -> children[index] == NULL)
                itr -> children[index] = new TrieNode();
            itr = itr -> children[index];
        }
        itr -> isWord = true;
    }
    bool search(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = (int)(word[i] - 'a');
            if (itr -> children[index] == NULL) return false;
            itr = itr -> children[index];
        }
        return itr -> isWord;
    }
    TrieNode *root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.add(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, 0, trie.root);
    }
    bool searchWord(string &word, int offset, TrieNode *itr) {
        if (itr == NULL) return false;
        for (int i = offset; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (searchWord(word, i + 1, itr -> children[j]))
                        return true;
                }
                return false;
            } else {
                int index = (int)(word[i] - 'a');
                if (itr -> children[index] == NULL)
                    return false;
                itr = itr -> children[index];
            }
        }
        if (itr -> isWord) return true;
        else return false;
    }
private:
    Trie trie;
};

int main() {
    // Your WordDictionary object will be instantiated and called as such:
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    wordDictionary.addWord("paper");
    cout << wordDictionary.search("pattern") << endl;
    cout << wordDictionary.search("word") << endl;
    cout << wordDictionary.search("w.rd") << endl;
    cout << wordDictionary.search("paper") << endl;
    cout << wordDictionary.search("p.p..") << endl;
    return 0;
}
