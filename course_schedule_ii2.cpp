/* - vector<int> v; ==> reserse(v.begin(), v.end()) reverses vector v
 * - to check if a graph has cycle, run DFS and keeps a path from root to the current node,
 *   and check if the path revisits its own nodes
 * - to output the course schedule, run DFS and output nodes via post-order traversal
 * - both set<int> s; and map<int, int> mp; have count() member function, i.e. s.count(3)
 *   and map.count(3)
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
            result[edges[i].second].push_back(edges[i].first);
        }
        return result;
    }

    int pickUnvisited(int numCourses, set<int> &visited) {
        int i;
        for (i = 0; i < numCourses; i++)
            if (visited.count(i) == 0) break;
        return i;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        if (numCourses == 0) return vector<int>();
        vector<vector<int> > graphs = convertToAdjList(numCourses, prerequisites);
        set<int> visited;
        vector<int> result;
        while (visited.size() < numCourses) {
            int i = pickUnvisited(numCourses, visited);
            set<int> path;
            path.insert(i);
            if (!visit(graphs, i, visited, path, result)) return vector<int>();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool visit(vector<vector<int> > &graphs, int i, set<int> &visited, set<int> &path,
        vector<int> &result) { // DFS & post-order traversal
        if (visited.count(i) > 0) return true;
        visited.insert(i);
        for(int j = 0; j < graphs[i].size(); j++) {
            if (path.count(graphs[i][j]) > 0) return false;
            path.insert(graphs[i][j]);
            if (!visit(graphs, graphs[i][j], visited, path, result)) return false;
            path.erase(graphs[i][j]);
        }
        result.push_back(i);
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
    vector<int> order = solution.findOrder(4, courses);
    for (int i = 0; i < order.size(); i++) cout << order[i] << " ";
    cout << endl;
    return 0;
}
