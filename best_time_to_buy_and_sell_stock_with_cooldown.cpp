/* - the problem can be solved via dynamic programming:
 *   the max profit of subarray prices[0...i] can be deduced if the max profits to subarrays
 *   prices[0...i'] are all computed for i' < i
 * - besides, recording the max profit and remember if the answer achieving the max profit
 *   sold the stock at each index i
 *   i.e. the answer at index i stores the max profit and whether the stock is sold at index i
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<pair<int, int> > answers;
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) {
                answers.push_back(make_pair(0, false));
            } else if (i == 1) {
                int profit = prices[1] - prices[0];
                if (profit > 0)
                    answers.push_back(make_pair(profit, true));
                else
                    answers.push_back(make_pair(0, false));
            } else {
                int maxProfit = INT_MIN;
                for (int j = 0; j < i; j++) {
                    int profit = prices[i] - prices[j];
                    if (profit > 0) {
                        if (j - 1 >= 0 && !answers[j - 1].second)
                            profit += answers[j - 1].first;
                        else if (j - 2 >= 0 && answers[j - 1].second)
                            profit += answers[j - 2].first;
                    }
                    if (maxProfit < profit) maxProfit = profit;
                }
                if (maxProfit > answers[i - 1].first)
                    answers.push_back(make_pair(maxProfit, true));
                else
                    answers.push_back(make_pair(answers[i - 1].first, false));
            }
        }
        return answers.back().first;
    }
};

int main() {
    int a[] = { 1, 2, 3, 0, 2 };
    vector<int> prices(a, a + 5);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
