/* - the problem can be solved via recursion
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) { // choose k out of 1..n
        vector<vector<int> > result;
        vector<int> solution;
        find(1, n, k, solution, result);
        return result;
    }

    void find(int start, int end, int k, vector<int> &solution, vector<vector<int> >&result) {
        // base case
        if (k == 0) {
            result.push_back(solution);
        }
        // recursive case
        for (int i = start; i <= end; i++) { // choose next number from [start, end]
            solution.push_back(i);
            find(i + 1, end, k - 1, solution, result);
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
