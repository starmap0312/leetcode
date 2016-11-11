/* - complete only one transaction
 * - the problem can be solved by keeping track of the minimum price on the fly
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minvalue = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (i > 0) {
                int p = prices[i] - minvalue;
                if (p > profit) {       // update the profit
                    profit = p;
                }
            }
            if (prices[i] < minvalue) { // update the minvalue
                minvalue = prices[i];
            }
        }
        return profit;
    }
};

int main() {
    int a[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(a, a + 6);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
