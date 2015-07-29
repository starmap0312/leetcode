/* - vector<int> v1, v2; ==> append two vectors: v1.insert(v1.end(), v2.begin(), v2.end())
 * - set<int> s1, s2;    ==> union two sets: s1.insert(s2.begin(), s2.end())
 * - class Node {
 *       vector<Node *> outgoing;
 *   };
 * - void DFS(Node* cur, set<Node*> &visited) {
 *       if (visited.count(cur) > 0) return;
 *       visited.insert(cur);
 *       for (int i = 0; i < cur -> outgoing.size(); i++)
 *           DFS(cur -> outgoing[i], visited);
 *   }
 * - void BFS(Node * start) {
 *       queue<Node *> q;
 *       set<Node *> visited;
 *       q.push(start);
 *       while (!q.empty()) {
 *           Node * cur = q.front(); q.pop();
 *           if (visited.count(cur) == 0) {
 *               visited.insert(cur);
 *               for (int i = 0; i < cur -> outgoing.size(); i++)
 *                   q.insert(cur -> outgoing[i]);
 *           }
 *       }
 *   }
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > convertToAdjList(int numCourses, vector<pair<int, int> >&edges) {
        vector<vector<int> > result;
        for (int i = 0; i < numCourses; i++)
            result.push_back(vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            result[edges[i].first].push_back(edges[i].second);
        }
        return result;
    }

    int pickUnvisited(int numCourses, set<int> &visited) {
        int i;
        for (i = 0; i < numCourses; i++)
            if (visited.count(i) == 0) break;
        return i;
    }
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graphs = convertToAdjList(numCourses, prerequisites);
        set<int> visited;
        while (visited.size() < numCourses) {
            int i = pickUnvisited(numCourses, visited);
            set<int> path;
            path.insert(i);
            if (!visit(graphs, i, visited, path)) return false;
        }
        return true;
    }
    bool visit(vector<vector<int> > &graphs, int i, set<int> &visited, set<int> &path) {
        if (visited.count(i) > 0) return true;
        visited.insert(i);
        for(int j = 0; j < graphs[i].size(); j++) {
            if (path.count(graphs[i][j]) > 0) return false;
            path.insert(graphs[i][j]);
            if (!visit(graphs, graphs[i][j], visited, path)) return false;
            path.erase(graphs[i][j]);
        }
        return true;
    }
};

int main() {
    vector<pair<int, int> > courses;
    courses.push_back(make_pair(0, 3));
    courses.push_back(make_pair(1, 3));
    courses.push_back(make_pair(2, 0));
    courses.push_back(make_pair(2, 1));
    Solution solution;
    cout << solution.canFinish(4, courses) << endl;
    return 0;
}
