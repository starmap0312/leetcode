/* - the problem can be solved by a two-phases algorithm:
 *   first, scan from left to right and update all increasing pairs
 *   next, scan from right to left and update all reversely increasing pairs
 * - the problem is simlar to the problem of "trapping rain water"
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        for (int i = 0; i < candies.size(); i++)
            cout << candies[i] << " ";
        cout << endl;
        return findSum(candies);
    }
    int findSum(vector<int> &candies) {
        int sum = 0;
        for (int i = 0; i < candies.size(); i++)
            sum += candies[i];
        return sum;
    }
};

int main() {
    int a[] = { 1, 3, 4, 3, 2, 1 };
    vector<int> ratings(a, a + 6);
    Solution solution;
    cout << solution.candy(ratings) << endl;
    return 0;
}
