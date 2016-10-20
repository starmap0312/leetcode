/* - exhaust all possibilities using recursion
 *
 *   pseudo-code
 *
 *   void solve(vector<int> &solution, int index) {
 *       // base case
 *       if (some_condition) {
 *           output the solution, or save the solution for later output
 *       }
 *       // inductive case
 *       for (every possible choice i) { // if the uniqueness constraint is imposed, we need to bypass some
 *           // make a choice            // choices, so that no duplicated solutions are outputted
 *           mark choice i as chosen
 *           solve(solution, i);
 *           // unmake the choice
 *           unmark choice i
 *       }
 *   }
 */
#include <iostream>

using namespace std;

int main() {
    return 0;
}
