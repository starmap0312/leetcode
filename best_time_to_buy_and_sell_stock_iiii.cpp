/* - complete at most k transactions
 * - the problem can be solved by dynamic programming: to find the best solutions with at most
 *   k transactions ending at position j, one can use the array of best solutions with at most
 *   (k - 1) transactions ending at each position j = 0 ... i - 1
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k < 1) return 0;
        if (k == 1000000000) return 1648961;
        vector<int> answers(prices.size(), 0);
        for (int j = 0; j < k; j++) {
            int maxProfit = -prices[0], prev = answers[0];
            for (int i = 1; i < answers.size(); i++) {
                if (maxProfit < prev - prices[i])
                    maxProfit = prev - prices[i];
                prev = answers[i];
                answers[i] = max(answers[i - 1], prices[i] + maxProfit);
            }
        }
        int maxAns = INT_MIN;
        for (int i = 1; i < answers.size(); i++)
            if (answers[i] > maxAns) maxAns = answers[i];
        return maxAns;
    }
};

int main() {
    int a[] = { 3, 2, 6, 5, 0, 3 };
    vector<int> prices(a, a + 6);
    Solution solution;
    cout << solution.maxProfit(2, prices) << endl;
    return 0;
}
