/* - the problem can be solved in linear time by scanning from left to right once
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        else if (prices.size() == 2) return max(prices[1] - prices[0], 0);
        int minimum = prices[0], profit = INT_MIN;
        vector<int> ans(1, INT_MIN);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - minimum > profit)
                profit = max(0, prices[i] - minimum);
            if (i + 1 < prices.size())
                ans.push_back(max(ans[i - 1], profit - prices[i + 1]));
            if (prices[i] < minimum)
                minimum = prices[i];
        }
        int maxSum = INT_MIN;
        for (int i = 2; i < prices.size(); i++) {
            if (ans[i - 1] + prices[i] > maxSum)
                maxSum = prices[i] + ans[i - 1];
        }
        return max(maxSum, profit);
    }
};

int main() {
    int a[] = { 1, 2, 4 };
    vector<int> prices(a, a + 3);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
