/* - use adjacency list to solve the problem
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Node {
public:
    Node(string s) { word = s; }
    string word;
    vector<Node *> neighbors;
    vector<Node *> backwards;
};

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, 
        unordered_set<string> &wordList) {
        vector<Node *> nodes;
        createNodes(beginWord, endWord, wordList, nodes);
        createEdges(nodes);
        createBackwards(nodes);
        vector<string> solution;
        solution.push_back(nodes[1] -> word);
        findSolutions(nodes, nodes[1], solution);
        destroy(nodes);
        return solutions;
    }

    void createNodes(string beginWord, string endWord, unordered_set<string> &wordList,
        vector<Node *> &nodes) {
        nodes.push_back(new Node(beginWord)), nodes.push_back(new Node(endWord));
        for (unordered_set<string>::iterator itr = wordList.begin(); itr != wordList.end(); itr++) {
            nodes.push_back(new Node(*itr));
        }
    }

    void createEdges(vector<Node *> &nodes) {
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = i + 1; j < nodes.size(); j++) {
                if (hasEdge(nodes[i] -> word, nodes[j] -> word)) {
                    (nodes[i] -> neighbors).push_back(nodes[j]);
                    (nodes[j] -> neighbors).push_back(nodes[i]);
                }
            }
        }
    }

    void createBackwards(vector<Node *> &nodes) {
        unordered_set<Node *> visited, next;
        visited.insert(nodes[0]), next.insert(nodes[0]);
        while (!next.empty() && visited.find(nodes[1]) == visited.end()) {
            unordered_set<Node *> tmp;
            for (unordered_set<Node *>::iterator itr = next.begin(); itr != next.end(); itr++) {
                for (vector<Node *>::iterator nbr = ((*itr) -> neighbors).begin();
                    nbr != ((*itr) -> neighbors).end(); nbr++) {
                    if (visited.find(*nbr) == visited.end()) {
                        ((*nbr) -> backwards).push_back(*itr);
                        tmp.insert(*nbr);
                    }
                }
            }
            visited.insert(tmp.begin(), tmp.end());
            next = tmp;
        }
    }

    void findSolutions(vector<Node *> &nodes, Node *cur, vector<string> &solution) {
        Node *beginNode = nodes[0], *endNode = nodes[1];
        if (cur == beginNode) {
            solutions.push_back(vector<string>());
            for (int i = solution.size() - 1; i >= 0; i--)
                (solutions.back()).push_back(solution[i]);
            return;
        }
        for (vector<Node *>::iterator itr = (cur -> backwards).begin();
            itr != (cur -> backwards).end(); itr++) {
            solution.push_back((*itr) -> word);
            findSolutions(nodes, *itr, solution);
            solution.pop_back();
        }
    }

    void destroy(vector<Node *> &nodes) {
        for (vector<Node *>::iterator itr = nodes.begin(); itr != nodes.end(); itr++)
            delete *itr;
    }

    bool hasEdge(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        int count = 0;
        for (int i = 0; i < s1.size() && count <= 1; i++) {
            if (s1[i] != s2[i]) count++;
        }
        if (count == 1) return true;
        else return false;
    }

private:
    vector<vector<string> > solutions;
};

int main() {
    string beginWord = "hit", endWord = "cog";
    unordered_set<string> wordList;
    wordList.insert("hot"), wordList.insert("dot");
    wordList.insert("dog"), wordList.insert("lot");
    wordList.insert("log");
    Solution solution;
    vector<vector<string> > solutions = solution.findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) 
            cout << solutions[i][j] << " ";
        cout << endl;
    }
    return 0;
}
