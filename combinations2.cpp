/* - similar idea to the previous solution, but
 *   try to exhaust all possible choices using recursion
 * - this solution is more efficient than the previous solution, as it does not return every
 *   subset of choices (the return solution uses pass-by-value)
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
        vector<int> choices;
        choose(n, k, 1, choices, result);
        return result;
    }

    void choose(int n, int k, int num, vector<int> &choices, vector<vector<int> > &result) {
       if (choices.size() == k) {
           result.push_back(choices);
           return;
       }
       if (num > n) return;
       choices.push_back(num);
       // choice 1: pick num
       choose(n, k, num + 1, choices, result);
       // undo the choice
       choices.pop_back();
       // choice 2: do not pick num 
       choose(n, k, num + 1, choices, result);
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
