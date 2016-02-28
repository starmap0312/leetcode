/* - the problem can be easily solved by keeping the minimum price read so far
 *   scan the prices once and compute the difference of the current price and the minimum price
 *   read so far, and update the maximum profit if needed
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int minPrice = prices[0], maxDiff = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            if (profit > maxDiff) maxDiff = profit;
            if (prices[i] < minPrice) minPrice = prices[i];
        }
        return max(0, maxDiff);
    }
};

int main() {
    return 0;
}
