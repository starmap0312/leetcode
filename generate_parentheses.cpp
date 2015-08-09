/* - use recursion, at each node of the decision tree, you can either choose to add a '('
 *   or undo the choice and add a ')' instead
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> parentheses;
        vector<string> result;
        generate(n, 0, parentheses, result);
        return result;
    }
    void generate(int n, int k, vector<char> &parentheses, vector<string> &result) {
        if (n == 0 && k == 0) {
            string s = "";
            for (int i = 0; i < parentheses.size(); i++) {
                s += parentheses[i];
            }
            result.push_back(s);
        }
        // choice 1
        if (n > 0) {
            parentheses.push_back('(');
            generate(n - 1, k + 1, parentheses, result);
            parentheses.pop_back();
        }
        // choice 2
        if (k > 0) {
            parentheses.push_back(')');
            generate(n, k - 1, parentheses, result);
            parentheses.pop_back();
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
