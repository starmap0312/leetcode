/* - note that the algorithm must be able to parse large numbers
 *   therefore, use type long instead of int
 * - the algorithm examine all possible expression
 *   ex. 232  ==> input num string
 *       consider all possible parsed numbers of the input string:
 *       2     3     2
 *       23    2
 *       2     32
 *       232
 *       consider all possible operators that can be put into the numbers:
 *       2  +  3  +  2
 *       2  +  3  -  2
 *       2  +  3  *  2
 *       2  -  3  +  2
 *       ....
 * - for each derived expression, the evaluation time must be fast enough to pass the tests
 *   ex.  2 + 3 * 4 + 5  ==> input expression to be evaluated: numbers[0...3]
 *        a two-phases approach: (too slow)
 *        2 + 12 + 5 ==> first phase
 *        19         ==> second phase
 *        a one-phase approach: maintain two numbers cur and diff during the traversal
 *        2 + 3 * 4 - 5
 *        -----          ==> cur = 5, diff = +3
 *        ---------      ==> cur = (5 - 3) + 3 * 4 = 14, diff = 3 * 4 = +12
 *                           i.e. update: cur  <- (cur - diff) + (diff * numbers[2])
 *                                        diff <- diff * numbers[2]
 *        -------------  ==> cur = 14 + 5, diff = -5
 *                           i.e. update: cur  <- (cur - numbers[3])
 *                                        diff <- -numbers[3]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.size() == 0) return result;
        vector<long> numbers;
        getAllNumbers(num, numbers, 0);
        for (int i = 0; i < allNumbers.size(); i++) {
            vector<char> choices;
            solve(allNumbers[i], choices, target);
        }
        return result;
    }

    void solve(vector<long> &numbers, vector<char> &choices, int target) {
        if (choices.size() == numbers.size() - 1) {
            if (evaluate(numbers, choices) == target)
                result.push_back(getExpression(numbers, choices));
            return;
        }
        char operators[] = { '+', '-', '*'};
        for (int i = 0; i < 3; i++) {
            choices.push_back(operators[i]);
            solve(numbers, choices, target);
            choices.pop_back();
        }
    }

    string getExpression(vector<long> &numbers, vector<char> &choices) {
        string result = "";
        for (int i = 0; i < choices.size(); i++)
            result += (to_string(numbers[i]) + choices[i]);
        result += to_string(numbers.back());
        return result;
    }

    long evaluate(vector<long> &numbers, vector<char> &choices) {
        long cur = numbers[0], diff = numbers[0];
        for (int i = 0; i < choices.size(); i++) {
            if (choices[i] == '*') {
                cur = (cur - diff) + (diff * numbers[i + 1]);
                diff = diff * numbers[i + 1];
            } else {
                cur = (choices[i] == '+'? cur + numbers[i + 1]: cur - numbers[i + 1]);
                diff = (choices[i] == '+'? numbers[i + 1]: -numbers[i + 1]);
            }
        }
        return cur;
    }

    void getAllNumbers(string &num, vector<long> &numbers, int i) {
        if (i == num.size()) {
            allNumbers.push_back(numbers);
        } else if (num[i] == '0') {
            numbers.push_back(0);
            getAllNumbers(num, numbers, i + 1);
            numbers.pop_back();
        } else {
            for (int j = i; j < num.size(); j++) {
                numbers.push_back(atol(num.substr(i, j - i + 1).c_str()));
                getAllNumbers(num, numbers, j + 1);
                numbers.pop_back();
            }
        }
    }

private:
    vector<string> result;
    vector<vector<long> > allNumbers;
};

int main() {
    string num = "232";
    int target = 8;
    Solution solution;
    vector<string> rc = solution.addOperators(num, target);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
