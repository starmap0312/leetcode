/* - the problem can be solved via dynamic programming: the answer of number n can be computed
 *   as follows if the answers of numbers 1 ... n - 1 are already computed
 *   ex. 1  2  3  4  5  6  7  8  9  10  11  12  ==> to compute the answer of number 12
 *       1  4  9  ...                           ==> perfect square numbers
 *       we have that 12 = 11 + 1  ==> (the answer of number 11) + 1
 *                       =  8 + 4  ==> (the answer of number  8) + 1
 *                       =  3 + 9  ==> (the answer of number  3) + 1
 *       therefore, the answer of number 12 is the minimum of the above 3 possibilities
 * - the time required is O(n sqrt(n))
 * - there exists a combinatorial approach that takes O(sqrt(n)) time
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = computeSquares(n);
        vector<int> answers;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < squares.size(); j++) {
                if (squares[j] > i + 1) break;
                if (squares[j] == i + 1) {
                    if (answers.size() < i + 1) answers.push_back(1);
                    else answers[i] = 1;
                    break;
                }
                if (answers.size() < i + 1) 
                    answers.push_back(answers[i - squares[j]] + 1);
                else if (answers[i - squares[j]] + 1 < answers[i])
                    answers[i] = answers[i - squares[j]] + 1;
            }
        }
        return answers.back();
    }

    vector<int> computeSquares(int n) {
        vector<int> result;
        int square = 1;
        while (square * square <= n) {
            result.push_back(square * square);
            square++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numSquares(12) << endl;
    cout << solution.numSquares(13) << endl;
    return 0;
}
