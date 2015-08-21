#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int minimum = INT_MAX, profit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            if (i > 0 && prices[i] - minimum > profit)
                profit = prices[i] - minimum;
            if (prices[i] < minimum)
                minimum = prices[i];
        }
        return profit;
    }
};

int main() {
    return 0;
}
