/* - observe that the problem can be solved by summing up all the rising curves
 *   to do that, just add up all positive differences between two consecutive time points
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) result += diff;
        }
        return result;
    }
};

int main() {
    int a[] = { 1, 3, 5, 2, 3, 1 };
    vector<int> prices(a, a + 6);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
