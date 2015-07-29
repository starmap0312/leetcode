/* 
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<vector<int>, int> > convertToAdjList(int numCourses, 
        vector<pair<int, int> >&edges) {
        vector<pair<vector<int>, int> > result;
        for (int i = 0; i < numCourses; i++)
            result.push_back(make_pair(vector<int>(), 0));
        for (int i = 0; i < edges.size(); i++) {
            result[edges[i].second].first.push_back(edges[i].first);
            result[edges[i].first].second++;
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
        vector<pair<vector<int>, int> > graphs = convertToAdjList(numCourses, prerequisites);
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (graphs[i].second == 0) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (find(result.begin(), result.end(), i) == result.end() && 
                graphs[i].second == 0) {
                result.push_back(i);
                for (int j = 0; j < graphs[i].first.size(); j++) {
                    int neighbor = graphs[i].first[j];
                    graphs[neighbor].second--;
                    q.push(neighbor);
                }
            }
        }
        if (result.size() != numCourses) return vector<int>(); // if there are nodes unreachable
        return result;
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
