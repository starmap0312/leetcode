/* - find the shortest-path from beginWord to endWord using breadth-first search
 *
 *                 hit
 *                  |
 *              _  hot _
 *              |       |
 *             dot     lot
 *              |       |
 *             dog     log
 *              |
 *             cog
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int length = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {   // pop out and examine all the next level nodes
                string word = q.front();
                q.pop();
                if (has_edge(word, endWord)) {          // if the node can reach endWord, return
                    return length + 1;
                }
                for (int i = 0; i < word.size(); i++) { // if the node cannot reach endWord
                    char c = word[i];
                    for (int j = 0; j < 26; j++) {      // push all its unvisited neighbors to the queue
                        word[i] = 'a' + j;
                        if (wordList.find(word) != wordList.end()) {
                            q.push(word);
                            wordList.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            length++;
        }
        return 0;
    }

    bool has_edge(string u, string v) {
        int count = 0;
        for (int k = 0; k < u.size(); k++) {
            if (u[k] != v[k]) {
                if (count == 0) {
                    count++;
                } else {
                    return false;
                }
            }
        }
        return (count == 1);
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    unordered_set<string> wordDict;
    string dict[] = { "hot","dot","dog","lot","log" };
    for (int i = 0; i < 5; i++) {
        wordDict.insert(dict[i]);
    }
    Solution solution;
    cout << solution.ladderLength(beginWord, endWord, wordDict) << endl;
    return 0;
}
