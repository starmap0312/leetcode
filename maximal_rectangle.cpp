/* - vector<int> v(n, 0); ==> initialize a vector of zeros with size n
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int max_area = 0;
        if (matrix.size() == 0) return max_area;
        vector<int> extension = vector<int>(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') extension[j] += 1;
                else extension[j] = 0;
                int min_extension = extension[j];
                for (int k = j; k >= 0; k--) {
                    min_extension = min(min_extension, extension[k]);
                    max_area = max(max_area, (j - k + 1) * min_extension);
                }
            }
        }
        return max_area;
    }
};

int main() {
    vector<vector<char> > matrix;
    char a[2] = {'1', '0'};
    vector<char> v(a, a + 2);
    matrix.push_back(v);
    matrix.push_back(v);
    Solution solution;
    cout << solution.maximalRectangle(matrix) << endl;
    return 0;
}
