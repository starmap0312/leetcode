/* - a brute-force approach is to try all possible permutations in a lexicographical order
 *   use recursion and traverse the possibilities in a depth-first search approach
 *   increment the counter at the leaf nodes, and continue until the k-th leaf is visited
 * - an improved approach: observe that to identify the k-th leaf, we do not need to actually
 *   visit all the leaves
 *   instead, at each level of the tree, determine which subtree of the node contains the
 *   k-th leaf, and go downwards to that subtree until the k-th leaf is reached
 * - example:
 *   { 1, 2, 3, 4 } <== n = 4
 *                      k = 10
 * 1) determine the first downward step from the root
 *    (4 - 1)! = 3! = 6, meaning that at this level each subtree of the root contains 6 leaves
 *    i.e. 
 *      (1)234
 *      (1)243
 *      (1)324
 *      (1)342
 *      (1)423
 *      (1)432
 *    as 6 < 10 <= 12, the first downward step is towardsthe second subtree, i.e. choose 2
 *    hence, remaining set = { 1, 3, 4 }, remaining count = 10 - 6 = 4
 * 2) determine the second downward step
 *    (3 - 1)! = 2! = 2, meaning that at this level each subtree contains 2 leaves
 *    i.e.
 *      (1)34
 *      (1)43
 *    as 2 < 4 <= 4, the second downward step is towards the second subtree, i.e. choose 3
 *    hence, remaining set = { 1, 4 }, remaining count = 4 - 2 = 2
 * 3) determine the third downward step
 *    (2 - 1)! = 1! = 1, meaning that at this level each subtree contains 1 leaf
 *    i.e.
 *      (1)4 
 *    as 1 < 2 <= 2, the third downward step is towards the second subtree, i.e. choose 4
 *    hence, remaining set = { 1 }, remaining count = 2 - 1 = 1
 * 4) determine the fourth downward step
 *    only one element left in the remaining step, i.e. we can only choose 1
 *    hence, remaining set = { }, remaining count = 1 - 1 = 0
 * 5) the final result is 2341
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() : permute_string("") { }
    string getPermutation(int n, int k) {
        vector<int> remaining;
        for(int i = 1; i <= n; i++) remaining.push_back(i);
        downward(remaining, k);
        return permute_string;
    }

    void downward(vector<int> &remaining, int k) {
        if (remaining.size() == 0) return;
        int denominator = factorial(remaining.size() - 1);
        int index = (k - 1) / denominator;
        permute_string += to_string(remaining[index]);
        remaining.erase(remaining.begin() + index);
        downward(remaining, k - denominator * index);
    }

    // factorial(k) returns the value of k!
    int factorial(int k) {
        int result = 1;
        for(int i = 1; i <= k; i++) result *= i;
        return result;
    }

private:
    string permute_string;
};

int main() {
    Solution solution;
    cout << solution.getPermutation(4, 10) << endl;
    return 0;
}
