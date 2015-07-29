#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows == 0) return vector<vector<int> >();
        vector<vector<int> > result;
        vector<int> row;
        row.push_back(1);
        result.push_back(row);
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < result[i - 1].size() - 1; j++)
                row.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.generate(3);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
