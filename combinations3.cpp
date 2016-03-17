/* - another way of exhausting all possible choices by recursion
 * - the idea used here is similar to that of "subsets" and "subsets_ii" problems
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) return result;
        vector<int> choices;
        choose(n, k, 1, choices, result);
        return result;
    }

    void choose(int n, int k, int num, vector<int> &choices, vector<vector<int> >& result) {
        if (choices.size() == k) {
            result.push_back(choices);
            return;
        }
        // the choice of the next number is in-between num..n
        for (int i = num; i <= n; i++) {
            choices.push_back(i); // pick number i
            choose(n, k, i + 1, choices, result); // recursive call
            choices.pop_back(); // undo the choice
        }
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
