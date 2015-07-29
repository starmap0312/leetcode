/* - to output the course schedule, run BFS and output nodes without inbound edges one by one
 * - use queue<int> q and while-loop to realize BFS
 *   while (!q.empty()) {
 *       int i = q.front(); q.pop();
 *       if (node i is unvisited && and node i has no inbound edges) {
 *           node i is an initial node, so add node i to the result list
 *           decrement the inbound counts of node i's outgoing neighbors
 *           push all node i's outgoing neighbors to queue q
 *       }
 *   }
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    class Node {
    public:
        Node() : outgoing(vector<int>()), inbounds(0) { }
        vector<int> outgoing;
        int inbounds;
    };

    vector<Node> convertToAdjList(int numCourses, vector<pair<int, int> >&edges) {
        vector<Node> result;
        for (int i = 0; i < numCourses; i++)
            result.push_back(Node());
        for (int i = 0; i < edges.size(); i++) {
            result[edges[i].second].outgoing.push_back(edges[i].first);
            result[edges[i].first].inbounds++;
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
        vector<Node> graphs = convertToAdjList(numCourses, prerequisites);
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (graphs[i].inbounds == 0) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (find(result.begin(), result.end(), i) == result.end() && graphs[i].inbounds == 0) {
                result.push_back(i);
                for (int j = 0; j < graphs[i].outgoing.size(); j++) {
                    int neighbor = graphs[i].outgoing[j];
                    graphs[neighbor].inbounds--;
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
