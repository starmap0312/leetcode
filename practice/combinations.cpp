/* - the problem can be solved via recursion
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        find(solution, 1, n, k, result);
        return result;
    }

    void find(vector<int> &solution, int start, int n, int k, vector<vector<int> >&result) {
        // base case
        if (k == 0) {
            result.push_back(solution);
        }
        // recursive case
        for (int i = start; i <= n; i++) {
            solution.push_back(i);
            find(solution, i + 1, n, k - 1, result);
            solution.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int> > rc = solution.combine(4, 2);
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++)
            cout << rc[i][j] << " ";
        cout << endl;
    }
    return 0;
}
