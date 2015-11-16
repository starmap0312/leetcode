/* - unordered_set<T> cannot put pair<T, T> into it; however, set<T> can
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Node {
public:
    Node() : isWord(false) {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    Node *children[26];
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new Node(); 
    }
    void add(string s) {
        Node *itr = root;
        for (int i = 0; i < s.size(); i++) {
            if (itr -> children[s[i] - 'a'] == NULL)
                itr -> children[s[i] - 'a'] = new Node();
            itr = itr -> children[s[i] - 'a'];
        }
        itr -> isWord = true;
    }
    Node *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        Trie *trie = createTrie(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                set<pair<int, int> > visited;
                vector<char> solution;
                findSolution(board, trie -> root, make_pair(i, j), visited, solution);
            }
        }
        vector<string> result;
        for (unordered_set<string>::iterator itr = solutions.begin(); itr != solutions.end(); itr++)
            result.push_back(*itr);
        return result;
    }

    void findSolution(vector<vector<char> >& board, Node *node, pair<int, int> position,
        set<pair<int, int> > &visited, vector<char> &solution) {
        if (position.first < 0 || position.first >= board.size() ||
            position.second < 0 || position.second >= board[0].size()) return;
        if (visited.find(position) != visited.end()) return;
        Node *nextNode = node -> children[board[position.first][position.second] - 'a'];
        if (nextNode == NULL) return;
        visited.insert(position);
        solution.push_back(board[position.first][position.second]);
        if (nextNode -> isWord) {
            string s = "";
            for (int i = 0; i < solution.size(); i++)
                s += solution[i];
            solutions.insert(s);
        }
        findSolution(board, nextNode, make_pair(position.first + 1, position.second), 
            visited, solution);
        findSolution(board, nextNode, make_pair(position.first - 1, position.second), 
            visited, solution);
        findSolution(board, nextNode, make_pair(position.first, position.second + 1), 
            visited, solution);
        findSolution(board, nextNode, make_pair(position.first, position.second - 1), 
            visited, solution);
        visited.erase(position);
        solution.pop_back();
    }

    bool inTrie(Node *node, char c) {
        if (node -> children[c - 'a'] != NULL) return true;
        return true;
    }

    Trie *createTrie(vector<string> &words) {
        Trie *trie = new Trie();
        for (int i = 0; i < words.size(); i++)
            trie -> add(words[i]);
        return trie;
    }
private:
    unordered_set<string> solutions;
};

int main() {
    string a[] = { "oath", "pea", "eat", "rain" };
    vector<string> words(a, a + 4);
    char b[][4] = {
        {'o', 'a', 'a', 'n'}, 
        {'e', 't', 'a', 'e'}, 
        {'i', 'h', 'k', 'r'}, 
        {'i', 'f', 'l', 'v'}
    };
    vector<char> v0(&b[0][0], &b[0][0] + 4);
    vector<char> v1(&b[1][0], &b[1][0] + 4);
    vector<char> v2(&b[2][0], &b[2][0] + 4);
    vector<char> v3(&b[3][0], &b[3][0] + 4);
    vector<vector<char> > board;
    board.push_back(v0), board.push_back(v1), board.push_back(v2), board.push_back(v3);
    Solution solution;
    vector<string> rc = solution.findWords(board, words);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
