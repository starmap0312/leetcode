/* - another approach of using recursion: faster than the first approach
 * - the same approach is used in "subsets" and "subsets_ii" problems
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (n < 1 || k == 0) return result;
        vector<int> list;
        choose(n, k, 1, list);
        return result;
    }
    void choose(int n, int k, int index, vector<int> &list) {
        if (list.size() == k) {
            result.push_back(list);
            return;
        }
        for (int i = index; i <= n; i++) {
            list.push_back(i);
            choose(n, k, i + 1, list);
            list.pop_back();
        }
    }
private:
    vector<vector<int> > result;
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
