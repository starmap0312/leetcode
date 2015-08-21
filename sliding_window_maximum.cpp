/* - use a doubly-ended queue to implement the algorithm
 *   deque<int> q; ==> q.front(), q.back(), q.push_front(3), q.pop_front(), 
 *                     q.push_back(3), q.pop_back()
 * - the deque maintains a strictly increasing numbers in a window, update numbers and remove
 *   numbers if go out of the window
 */
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<pair<int, int> > q;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                result.push_back(q.front().second);
                if (i - q.front().first >= k) q.pop_front();
            }
            add(q, make_pair(i, nums[i]));
        }
        if (!q.empty()) result.push_back(q.front().second);
        return result;
    }
    void add(deque<pair<int, int> > &q, pair<int, int> p) {
        while (!q.empty() && p.second >= q.back().second)
            q.pop_back();
        q.push_back(p);
    }
};

int main() {
    int a[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> nums(a, a + 8);
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums, 3);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
