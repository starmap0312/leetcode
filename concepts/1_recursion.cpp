/* - exhaust all possibilities using recursion
 *
 *   // pseudo-code
 *   void solve(vector<int> &solution, int index) {
 *       // base case
 *       if (some_condition) {
 *           output the solution, or save the solution for later output
 *       }
 *       // inductive case
 *       for (every possible choice i) {                // if the uniqueness constraint is imposed, we need to bypass some choices
 *           make a choice, and mark choice i as chosen //   so that no duplicated solutions are outputted
 *           solve(solution, i);                        // recursively solve the problem
 *           unmake the choice, and unmark choice i
 *       }
 *   }
 */
#include <iostream>

using namespace std;

int main() {
    return 0;
}
