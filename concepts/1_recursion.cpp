/* - exhaust all possibilities using recursion
 *
 *   // pseudo-code
 *   void solve(choice_state, solution_state) {
 *       // base case
 *       if (exhaust all choices & valid solution) {
 *           output the solution
 *       }
 *       // inductive case
 *       for (every possible choice i) {                  // if uniqueness constraint is imposed, bypass some choices to avoid duplication
 *           make choice i                                // derive new_choice_state & new_solution_state
 *           solve(new_choice_state, new_solution_state); // solve the problem recursively
 *           unmake choice i                              // revert choice_state & solution_state
 *       }
 *   }
 */
#include <iostream>
#include <vector>

using namespace std;

class Combination {
public:
    void choose(int k, int n) { // choose k numbers out of 1..n
        vector<int> solution;
        solve(k, 1, n, solution);
    }

    void solve(int k, int start, int end, vector<int> &solution) { // choose k numbers from [start, end]
        // base case
        if (k == 0) {
            for (int i = 0; i < solution.size(); i++)
                cout << solution[i] << " ";
            cout << endl;
            return;
        }
        // recursive case
        for (int i = start; i <= end; i++) {    // make a choice from [start, end]
            solution.push_back(i);              // add the chosen number to solution
            solve(k - 1, i + 1, end, solution); // solve the problem recursively
            solution.pop_back();                // remove the chosen number from solution
        }
    }
};

class UniquePermutations {
public:
    void permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> solution;
        solve(nums, solution);
    }

    void solve(vector<int> &remaining, vector<int> &solution) {
        // boundary case
        if (remaining.size() == 0) {
            for (int i = 0; i < solution.size(); i++)
                cout << solution[i] << " ";
            cout << endl;
            return;
        }
        // inductive case
        for (int i = 0; i < remaining.size(); i++) {
            if (i == 0 || remaining[i] != remaining[i - 1]) { // make only distinct choices, ex. [1, 2, 2] will choose only 1, 2
                int picked = remaining[i];                    // make the choice
                remaining.erase(remaining.begin() + i);
                solution.push_back(picked);
                solve(remaining, solution);                   // solve the problem recursively
                solution.pop_back();                          // unmake the choice
                remaining.insert(remaining.begin() + i, picked);
            }
        }
    }
};

int main() {
    cout << "example 1: combinations" << endl;
    Combination combination;
    combination.choose(2, 4);

    cout << "example 2: unique permutations" << endl;
    int a[] = { 1, 2, 1, 2 };
    vector<int> nums(a, a + 4); 
    UniquePermutations permutations;
    permutations.permuteUnique(nums);
    return 0;
}
