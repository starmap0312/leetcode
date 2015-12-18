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
        int sum = 0, ind = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] > prices[i]) {
                sum += (prices[i - 1] - prices[ind]);
                ind = i;
            }
        }
        sum += (prices[prices.size() - 1] - prices[ind]);
        return sum;
    }
};

int main() {
    return 0;
}
