/* - the problem can be solved efficiently via dynamic programming
 * - the input string is first tokenized as vectors of numbers and operators
 *   ex. 2  *  3  -  4  *  5        input string
 *      [0]   [1]   [2]   [3]  ==>  numbers[0...3]
 *         [0]   [1]   [2]     ==>  operators[0...2]
 * - the problem can then be solved via recursion based on the choice of the last operator
 *   ex. 2  *  3  -  4  *  5
 *      based on the choice of the last operator, we have the following possibilities
 *      (2) * (3  -  4  *  5)  ==> (2) * (the answer of substring 3 - 4 * 5)
 *      (2  *  3) - (4  *  5)  ==> (the answer of substring 2 * 3) - (the answer of substring 4 * 5)
 *      (2  *  3  -  4) * (5)  ==> (the answer of substring 2 * 3 - 4) * (5)
 *   therefore, if the answers of all the substrings are provided, one can easily obtain
 *   the answer of the complete string by unioning all the computed results
 * - finally, solve in a dynamic programming fasion, i.e. from bottom to top
 *   ex. 
 *      [i]    __________   ==> the answer of the complete input string (the final answer)
 *       3     2  3  4  5
 *                _______   ==> the answers of all length-3 substrings
 *             _______   
 *       2     2  3  4  5
 *                ____      ==> the answers of all length-2 substrings
 *             ____  ____
 *       1     2  3  4  5
 *             _  _  _  _   ==> the answers of all length-1 substrings
 *       0     2  3  4  5
 *             0  1  2  3 [j]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (input.size() == 0) return result;
        vector<int> numbers;
        vector<char> operators;
        tokenize(input, numbers, operators);
        vector<vector<vector<int> > > answers;
        for (int i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                vector<vector<int> > ans;
                for (int j = 0; j < numbers.size(); j++)
                    ans.push_back(vector<int>(1, numbers[j]));
                answers.push_back(ans);
            } else {
                vector<vector<int> > ans;
                for (int j = 0; j < numbers.size() - i; j++) {
                    vector<int> v;
                    for (int k = 0; k < i; k++) {
                        vector<int> rc = crossOperate(answers[k][j], operators[j + k], 
                            answers[i - k - 1][j + k + 1]);
                        v.insert(v.end(), rc.begin(), rc.end());
                    }
                    ans.push_back(v);
                }
                answers.push_back(ans);
            }
        }
        return answers.back().back();
    }

    vector<int> crossOperate(vector<int> &u, char op, vector<int> &v) {
        vector<int> result;
        for (int i = 0; i < u.size(); i++)
            for (int j = 0; j < v.size(); j++)
                result.push_back(operate(u[i], op, v[j]));
        return result;
    }

    int operate(int a, char op, int b) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return 0;
    }

    void tokenize(string input, vector<int> &numbers, vector<char> &operators) {
        int num = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isDigit(input[i])) {
                num = num * 10 + (input[i] - '0');
            } else {
                operators.push_back(input[i]);
                numbers.push_back(num);
                num = 0;
            }
        }
        numbers.push_back(num);
    }

    bool isDigit(char c) {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> rc = solution.diffWaysToCompute("2*3-4*5");
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
