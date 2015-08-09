/* - (select k out of 1..n) can be recursively solved by:
 *   (not select n and select k out of 1..n - 1) + (select n and select k - 1 out of 1..n - 1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (k == 0 || n < 1) return result;
        if (k == 1) {
            for (int i = 1; i <= n; i++)
                result.push_back(vector<int>(1, i));
            return result;
        }
        result = combine(n - 1, k);
        vector<vector<int> > with = combine(n - 1, k - 1);
        for (int i = 0; i < with.size(); i++) {
            with[i].push_back(n);
            result.push_back(with[i]);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.combine(4, 2);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
