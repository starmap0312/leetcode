/* - construct a graph based on the input, find the shortedst path from the node of beginWord
 *   to the node of endWord. the path indicates a transformation sequence from beginWord to
 *   endWord
 * - the algorithm can be improved by not constructing the graph, but operate on the wordDict
 *   and a queue of strings
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Node {
public:
    string word;
    Node *backtrack;
    vector<Node*> neighbors;
    Node(string s) : word(s), backtrack(NULL), neighbors(vector<Node*>()) { }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return 0;
        vector<Node*> nodes = createNodes(beginWord, endWord, wordDict);
        createEdges(nodes);
        findPath(nodes);
        return findPathLength(nodes);
    }
    vector<Node*> createNodes(string beginWord, string endWord, unordered_set<string>& wordDict) {
        vector<Node*> result;
        result.push_back(new Node(beginWord));
        for (unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); itr++) 
            result.push_back(new Node(*itr));
        result.push_back(new Node(endWord));
        return result;
    }
    void createEdges(vector<Node*> &nodes) {
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = i + 1; j < nodes.size(); j++) {
                if (isNext(nodes[i] -> word, nodes[j] -> word)) {
                    (nodes[i] -> neighbors).push_back(nodes[j]);
                    (nodes[j] -> neighbors).push_back(nodes[i]);
                }
            }
        }
    }
    bool isNext(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        bool diff = false;
        for (int i = 0; i < s1.size(); i++)
            if (diff && s1[i] != s2[i]) return false;
            else if (!diff && s1[i] != s2[i]) diff = true;
        if (diff) return true;
        return false;
    }
    void findPath(vector<Node*> &nodes) {
        unordered_set<Node*> visited;
        queue<Node*> q;
        visited.insert(nodes.front());
        q.push(nodes.front());
        while (!q.empty()) {
            Node *node = q.front();
            for (int i = 0; i < (node -> neighbors).size(); i++) {
                Node *nbr = (node -> neighbors)[i];
                if (visited.find(nbr) == visited.end()) {
                    nbr -> backtrack =  node;
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
            q.pop();
        }
    }
    int findPathLength(vector<Node*> &nodes) {
        Node *itr = nodes.back();
        int length = 0;
        while (itr -> backtrack != NULL) {
            length++;
            itr = itr -> backtrack;
        }
        length++;
        if (itr == nodes.front()) return length;
        else return 0;
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    unordered_set<string> wordDict;
    string dict[] = { "hot","dot","dog","lot","log" };
    for (int i = 0; i < 5; i++)
        wordDict.insert(dict[i]);
    Solution solution;
    cout << solution.ladderLength(beginWord, endWord, wordDict) << endl;
    return 0;
}
