/* - the problem represents a graph using a edge list (a list of all edges)
 *   ex. n = 4, edges = [ (1, 0), (1, 2), (1, 3) ]
 * - this approach first randomly chooses a root and find its height; it then check the heights
 *   of its neighbors to find if there is a smaller height; if no, output the chosen root;
 *   otherwise, set the root to the neighbor with the smallest height and repeat the procedure
 * - the time of this approach is too expensive and therefore does not pass the tests
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > neighbors = preprocess(n, edges);
        int root = n / 2;
        int rootHeight = findHeight(edges, neighbors, root, INT_MAX);
        unordered_set<int> visited;
        visited.insert(root);
        vector<int> result;
        while (visited.size() < n) {
            int minHeight = rootHeight, minNode = -1;
            for (int i = 0; i < neighbors[root].size(); i++) {
                int nbr = neighbors[root][i];
                if (visited.find(nbr) == visited.end()) {
                    visited.insert(nbr);
                    int height = findHeight(edges, neighbors, nbr, minHeight);
                    if (height <= minHeight) {
                        minNode = nbr;
                        minHeight = height;
                    }
                }
            }
            if (minHeight < rootHeight) {
                root = minNode;
            } else if (minNode != -1) {
                result.push_back(root), result.push_back(minNode);
                return result;
            } else {
                result.push_back(root);
                return result;
            }
        }
        return result;
    }

    vector<vector<int> > preprocess(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > result(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].first != edges[i].second) {
                result[edges[i].first].push_back(edges[i].second);
                result[edges[i].second].push_back(edges[i].first);
            }
        }
        return result;
    }

    int findHeight(vector<pair<int, int> >& edges, vector<vector<int> > &neighbors,
        int root, int minHeight) {
        unordered_set<int> visited;
        queue<int> q;
        visited.insert(root);
        q.push(root);
        int height = 0;
        while (!q.empty()) {
            queue<int> next;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int i = 0; i < neighbors[node].size(); i++) {
                    int nbr = neighbors[node][i];
                    if (visited.find(nbr) == visited.end()) {
                        visited.insert(nbr);
                        next.push(nbr);
                    }
                }
            }
            height++;
            if (height > minHeight) return INT_MAX;
            q = next;
        }
        return height;
    }
};

int main() {
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(5, 4));
    Solution solution;
    vector<int> rc = solution.findMinHeightTrees(6, edges);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
