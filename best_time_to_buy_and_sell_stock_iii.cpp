/* - complete at most two transactions
 * - the problem can be solved via dynamic programming
 *   1) first-pass
 *      we compute the answer of max profit for single transaction at every time i, denoted by profits[i]
 *   2) second-pass
 *      at time i, we pick the best choice i', where i' < i, so that
 *      profits[i'-1] + (prices[i] - prices[i']) is maximized
 *
 *      i.e. the value of best first transaction + second transaction is maximized
 *      to achieve that, we keep the maximum value of profits[i'-1] - prices[i'] for all i' < i
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        // first-pass: compute the answer of max profit for single transaction at every time i
        vector<int> profits;
        int profit = 0, minvalue = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (i > 0) {
                int value = prices[i] - minvalue;
                if (value > profit) {   // update the max profit
                    profit = value;
                }
            }
            profits.push_back(profit);
            if (prices[i] < minvalue) { // update the min value
                minvalue = prices[i];
            }
        }
        // second-pass: decide the second transaction to be prices[i] - prices[i'], so that
        //              profits[i'-1] + (prices[i] - prices[i']) is maximized
        profit = 0;
        int best_choice = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int value = prices[i] + best_choice;
            if (value > profit) {                 // update the max profit
                profit = value; 
            }
            int choice = profits[i - 1] - prices[i];
            if (choice > best_choice) {           // update the best choice
                best_choice = choice;
            }
        }
        return profit;
    }
};

int main() {
    int a[] = { 1, 2, 4 };
    vector<int> prices(a, a + 3);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
