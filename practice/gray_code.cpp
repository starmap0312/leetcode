/* - the problem can be solved via dynamic programming:
 *   the sequence of gray code for length n can be generated using the sequence of gray code
 *   for length n - 1
 *   ex. the sequence of gray code for length 1
 *         0
 *         1
 *       the sequence of gray code for length 2
 *       1) append 0 to the front of the sequence: [0, 1]
 *         (0) 0
 *         (0) 1
 *       2) append 1 to the front of the sequence, but in a reversed order: [1, 0]
 *         (1) 1
 *         (1) 0
 * - c++ assign operator, i.e. std::vector::operator=, will assign and replace its current
 *   contents and modify its size accordingly
 *   the time complexity for the operation is linear
 *   ex. vector<int> foo(3, 0);
 *       vector<int> bar(5, 0);
 *       bar = foo; // bar now contains [0, 0, 0] with size 3
 * - the problem has a more complicated solution by imaging the numbers of the sequence
 *   as the nodes of a graph, where two nodes has an edge if they differ by only one bit
 *   in this setting, the problem becomes to find a path that visited all the nodes of the
 *   graph once
 *   one can solve it via depth-first traversal with recursions: an rather inefficient solution
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for (int i = 0; i < n; i++) {
             vector<int> next;
             for (int j = 0; j < result.size(); j++)
                 next.push_back(result[j]);
             for (int j = result.size() - 1; j >= 0; j--)
                 next.push_back(result[j] + (1 << i));
             result = next; // assign the contents of next to result, requiring O(n) time
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> rc = solution.grayCode(2);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
