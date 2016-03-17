/* - a divide-and-conquer approach using recursion
 * - (select k out of 1..n) can be recursively solved by:
 *   case 1: n is not picked, and select k out of 1..n - 1
 *   case 2: n is picked, and select k - 1 out of 1..n - 1
 *   ex. select 2 out of 1..4
 *        i) 4 is not picked:
 *           select 2 out of 1..3 ==> [[1, 2], [1, 3], [2, 3]]
 *       ii) 4 is picked:
 *           select 1 out of 1..3 ==> [[1], [2], [3]]
 *                                ==> [[1, 4], [2, 4], [3, 4]]
 *       final result: [[1, 2], [1, 3], [2, 3], [1, 4], [2, 4], [3, 4]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // select k out of 1..n
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        // boundary cases: k <= 1 or n < 1
        if (k == 0 || n == 0) return result;
        else if (k == 1 && n > 0) {
            for (int i = 1; i <= n; i++)
                result.push_back(vector<int>(1, i));
            return result;
        }
        // case 1: n is not picked, and select k out of 1..n - 1
        result = combine(n - 1, k);
        // case 2: n is picked, and select k - 1 out of 1..n - 1
        vector<vector<int> > nIsPicked = combine(n - 1, k - 1);
        for (int i = 0; i < nIsPicked.size(); i++) {
            nIsPicked[i].push_back(n);
        }
        // combine the results of the two cases
        result.insert(result.end(), nIsPicked.begin(), nIsPicked.end());
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.combine(4, 2);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
