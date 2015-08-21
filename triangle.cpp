/* - use straightfoward recursion takes long time
 * - the problem can be solved via dynamic programming approach, computing the table from bottom
 *   to top
 * - the space required for the table can be reduced to O(n) instead of O(m * n), as only one
 *   row of the table needs to be kept while computing from bottom to top
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> minimum(triangle.back().size());
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == triangle.size() - 1) minimum[j] = triangle[i][j];
                else {
                    minimum[j] = min(minimum[j], minimum[j + 1]) + triangle[i][j];
                }
            }
        }
        return minimum[0];
    }
};

int main() {
    vector<vector<int> > triangle;
    vector<int> row1; row1.push_back(2);
    vector<int> row2; row2.push_back(3), row2.push_back(4);
    vector<int> row3; row3.push_back(6), row3.push_back(5), row3.push_back(7);
    vector<int> row4; row4.push_back(4), row4.push_back(1), row4.push_back(8), row4.push_back(3);
    triangle.push_back(row1), triangle.push_back(row2);
    triangle.push_back(row3), triangle.push_back(row4);
    Solution solution;
    cout << solution.minimumTotal(triangle) << endl;
    return 0;
}
