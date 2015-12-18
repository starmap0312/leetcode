/* - the approach resembles the solution for solving topological ordering
 *   i.e. first remove all the leaf nodes from the graph and then repeat the procedure
 *        until there is no more than 2 nodes exist in the graph
 *   the algorithm first establishes a vector of each node's neighbors and maintains
 *   a vector of degrees and a queue of leaf nodes
 *   after the removal of leaf nodes, the vector of degrees and the queue of leaf nodes
 *   must be updated with the help of the neighbors vector
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        unordered_set<int> remaining;
        for (int i = 0; i < n; i++) {
            remaining.insert(i);
        }
        vector<vector<int> > neighbors(n, vector<int>());
        vector<int> degrees(n, 0);
        preprocess(n, edges, neighbors, degrees);
        queue<int> q;
        while (remaining.size() > 2) {
            for (unordered_set<int>::iterator itr = remaining.begin();
                itr != remaining.end(); itr++) {
                if (degrees[*itr] == 1) q.push(*itr);
            }
            while (!q.empty()) {
                int node = q.front();
                for (int i = 0; i < neighbors[node].size(); i++) {
                    degrees[neighbors[node][i]]--;
                }
                remaining.erase(node);
                q.pop();
            }
        }
        return vector<int>(remaining.begin(), remaining.end());
    }

    void preprocess(int n, vector<pair<int, int> >& edges, vector<vector<int> > &neighbors,
        vector<int> &degrees) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].first != edges[i].second) {
                neighbors[edges[i].first].push_back(edges[i].second);
                neighbors[edges[i].second].push_back(edges[i].first);
                degrees[edges[i].first]++;
                degrees[edges[i].second]++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(5, 4));
    vector<int> rc = solution.findMinHeightTrees(6, edges);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
