/* - complete as many transactions as you like
 * - the problem can be solved by summing up all rising trends
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                profit += diff; 
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
