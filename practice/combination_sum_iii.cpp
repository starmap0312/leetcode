/* - the problem can be solved via recursion:
 *   the algorithm exhausts all combinations using recursion
 *   ex. k = 3, n = 9
 *       suppose that we have picked two numbers: [1, 2]
 *       use a for-loop to iterate all possibilities of the next number
 *       pick a number from [start, end]
 *
 *       [1, 2] +          3,         4,          5,           6
 *
 *                     start                                 end
 *                        ||                                  ||
 *                    (2 + 1)                         (9 - 1 - 2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> solution;
        vector<vector<int> > result;
        solve(k, n, solution, result); 
        return result;
    }

    void solve(int k, int n, vector<int> &solution, vector<vector<int> > &result) {
        // base case
        if (k <= 0 || n <= 0) {
            if (k == 0 && n == 0) result.push_back(solution);
            return;
        }

        // recursive case
        int start = (solution.size() == 0? 0: solution.back()) + 1;
        int end = min(9, n);
        // a for-loop that iterates all the possibilities of the next number that can be picked
        for (int i = start; i <= end; i++) {
            solution.push_back(i); // make a choice
            solve(k - 1, n - i, solution, result); // recursively solve the problem
            solution.pop_back(); // undo the choice
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int> > rc = solution.combinationSum3(3, 9);
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++)
            cout << rc[i][j] << " ";
        cout << endl;
    }
    return 0;
}
