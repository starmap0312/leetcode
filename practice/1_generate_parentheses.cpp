/* - the problem can be solved via recursion:
 *   keep track of the budget of pairs of parentheses that should be constructed
 *   keep track of the number of left parentheses that should be paired with right parentheses
 *   the recursive method can choose to generate a left or right parenthesis based on the values
 *   of budget and left
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> solution;
        vector<string> parentheses;
        generate(n, 0, solution, parentheses);
        return parentheses;
    }

    void generate(int budget, int numLeft, vector<char> &solution, vector<string> &parentheses) {
        if (budget == 0 && numLeft == 0) { // base case: if the budget is consumed and all left parentheses are paired up
            parentheses.push_back(convertToString(solution)); // then we obtain a valid solution
            return;
        }
        if (budget > 0) {  // choice 1: append a '(', only if there are some budget left
            solution.push_back('(');
            generate(budget - 1, numLeft + 1, solution, parentheses);
            solution.pop_back();
        }
        if (numLeft > 0) { // choice 2: append a ')', only if there are some left parentheses un-paired
            solution.push_back(')');
            generate(budget, numLeft - 1, solution, parentheses);
            solution.pop_back();
        }
    }

    string convertToString(vector<char> &solution) { // ex. [ (, ), (, (, ), ) ] ==> "()(())"
        string result = ""; 
        for (int i = 0; i < solution.size(); i++) {
            result += solution[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> rc = solution.generateParenthesis(3);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
