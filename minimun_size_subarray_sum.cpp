/* - the problem is resolved using a doubly ended queue, which supports operations like
 *   front(), push_front(3), pop_front(), back(), push_back(4), pop_back()
 * - the O(n) time algorithm works as follows:
 *   maintain a incresing prefix sums (deque), at each iteration check from the front of 
 *   the deque if there is an index starting from which and ending at current index 
 *   the sum of the segment is greater than or equal to the given parameter s
 *   if yes, check if the length of the segment starting from that index and ending at the 
 *   current index is shorter than the kept minimum length 
 *   (as we want the shortest segment, we can pop that index from the deque once done)
 *   finally, update the deque by pushing the current index to the end of the deque (needs to
 *   pop out those indices with larger prefix sums from the end of the deque)
 * - make_pair(3, 5) makes an instance of pair<int, int> (don't use make_pair<int, int>(3, 5)
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        deque<pair<int, int> > q;
        q.push_back(make_pair(0, 0));
        int prefixSum = 0, minLength = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int index = popDeque(q, s, prefixSum);
            if (index != -1) minLength = min(minLength, i + 1 - index);
            insertDeque(q, i + 1, prefixSum);
        }
        return (minLength == INT_MAX? 0: minLength);
    }
    void insertDeque(deque<pair<int, int> > &q, int index, int prefixSum) {
        while (!q.empty() && prefixSum <= q.back().second)
            q.pop_back();
        q.push_back(make_pair(index, prefixSum));
    }
    int popDeque(deque<pair<int, int> > &q, int s, int num) {
        int index = -1;
        while (!q.empty() && num - s >= q.front().second) {
            index = q.front().first;
            q.pop_front();
        }
        return index;
    }
};

int main() {
    int a[] = { 2, 3, 1, 2, 4, 3 };
    vector<int> nums(a, a + 6);
    Solution solution;
    cout << solution.minSubArrayLen(7, nums) << endl;
    return 0;
}
