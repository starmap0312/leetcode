/* - the problem can be solved via dynamic programming:
 *   we aim to compute the maximum profit at time i, denoted by profit[i]
 *   let value[i] = max_{0 <= k <= i - 2}(profit[k]) - prices[i]
 *   we have that profit[i] = max_{0 <= k <= i - 1}(value[k]) + prices[i]
 *   in the following implementation:
 *     maxValue = max_{0 <= k <= i - 1}(value[k]) is updated at each iteration 
 *     prevProfit2 = max_{0 <= k <= i - 2}(profit[k]) is updated at each iteration
 *   so that profit = profit[i] = max(0, maxValue + prices[i]) can be computed at each iteration
 * - the logic of the solution can be confusing at first glance:
 *   1) observe that the key is to maintain maxValue at each iteration i so that
 *      profit[i + 1] can be easily computed
 *   2) in order to maintain maxValue at each iteration i, we need the help of prevProfit2
 *   3) in order to maintain prevProfit2, we need the help of prevProfit
 *   4) finally, make sure that the initial values of maxValue, prevProfit, prevProfit2 are set
 *      correctly
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int prevProfit = 0, prevProfit2 = 0, maxValue = -prices[0], maxProfit = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int profit = max(0, maxValue + prices[i]);
            if (maxProfit < profit) maxProfit = profit;
            int value = prevProfit2 - prices[i];
            if (value > maxValue) maxValue = value;
            prevProfit2 = prevProfit;
            prevProfit = max(prevProfit, profit);
        }
        return maxProfit;
    }
};

int main() {
    int a[] = { 1, 2, 3, 0, 2 };
    vector<int> prices(a, a + 5);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
