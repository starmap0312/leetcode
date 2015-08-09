/* - use recursion, at each node of the decision tree, you can either choose to add a '('
 *   or undo the choice and add a ')' instead
 * - no need to use stack like the previous code version
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generate(n, n, s, result);
        return result;
    }
    void generate(int n, int k, string s, vector<string> &result) {
        if (n == 0 && k == 0) {
            result.push_back(s);
        }
        if (n > k) return;
        // choice 1
        if (n > 0) {
            generate(n - 1, k, s + '(', result);
        }
        // choice 2
        if (k > 0) {
            generate(n, k - 1, s + ')', result);
        }
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.generateParenthesis(3);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
