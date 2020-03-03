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
    void printParentheses(int n) {
        vector<char> parentheses;
        generate(n, 0, parentheses);
    }

    void generate(int budget, int numLeft, vector<char> &parentheses) {
        if (budget == 0 && numLeft == 0) { // base case: if the budget is consumed and all left parentheses are paired up
            print(parentheses); // then we obtain a valid solution
            return;
        }
        if (budget > 0) {  // choice 1: append a '(', only if there are some budget left
            parentheses.push_back('(');
            generate(budget - 1, numLeft + 1, parentheses);
            parentheses.pop_back();
        }
        if (numLeft > 0) { // choice 2: append a ')', only if there are some left parentheses un-paired
            parentheses.push_back(')');
            generate(budget, numLeft - 1, parentheses);
            parentheses.pop_back();
        }
    }

    void print(vector<char> &parentheses) { // ex. [ (, ), (, (, ), ) ] ==> "()(())"
        for (int i = 0; i < parentheses.size(); i++) {
            cout << parentheses[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    solution.printParentheses(3);
    return 0;
}
