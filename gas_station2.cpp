/* - consider the sequence diff[i] = gas[i] - cost[i]
 *   let maxsum[i] be the value of maximum sum segment ending at each position
 *   suppose that the answer of the problem is index i. we have that:
 *   1. maxsum[i - 1] < 0 if index i - 1 exists (otherwise, let diff[i'..i - 1], where i' < i, be 
 *      the maximum sum segment ending at i - 1. observe that i' is also the answer index, and 
 *      a contradiction occurs
 *   2. maxsum[i'] > 0 for all i' > i (an fact deduced from 1.)
 * - so the problem can be resolved for finding the last i - 1 where maxsum[i - 1] < 0, and returns
 *   index i as the answer
 * - the fact that the index found as above is the answer requires more proofs
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, total = 0, index = -1;
        for (int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if (sum < 0) {
                sum = 0;
                index = i;
            }
        }
        return (total < 0? -1: index + 1);
    }
};

int main() {
    return 0;
}
