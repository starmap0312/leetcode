/* - maintain an index for each number of the prime list: this index denotes the smallest 
 *   super ugly number in the sequence generated so far with which the multiplication may
 *   contribute to the next super ugly number of the sequence
 *   ex.  2,  7, 13, 19  ==> prime list
 *        i   j   k   l  ==> maintain four indices for each prime number
 *          1
 *       i,j,k,l
 *          1     2
 *        j,k,l   i
 *          1     2     4
 *        j,k,l         i
 *          1     2     4     7
 *         k,l    j     i
 *          1     2     4     7     8
 *         k,l    j           i
 *          1     2     4     7     8     13
 *          l    k,j          i
 *          1     2     4     7     8     13    14
 *          l     k     j           i
 *          1     2     4     7     8     13    14    16
 *          l     k     j                  i
 *   continue in this manner until the n-th super ugly number is produced
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> indices(primes.size(), 0);
        vector<int> ans(1, 1);
        while (n > 1) {
            int minimum = INT_MAX;
            for (int i = 0; i < indices.size(); i++) {
                int num = primes[i] * ans[indices[i]];
                if (num < minimum) minimum = num;
            }
            for (int i = 0; i < indices.size(); i++) {
                int num = primes[i] * ans[indices[i]];
                if (num == minimum) indices[i]++;
            }
            ans.push_back(minimum);
            n--;
        }
        return ans.back();
    }
};

int main() {
    Solution solution;
    int a[] = { 2, 7, 13, 19 };
    vector<int> primes(a, a + 4);
    cout << solution.nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
