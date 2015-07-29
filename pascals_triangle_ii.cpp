#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for (int i = 1; i < rowIndex + 1; i++) {
            int prev = 1;
            for (int j = 0; j < row.size() - 1; j++) {
                int tmp = row[j + 1];
                row[j + 1] = prev + row[j + 1];
                prev = tmp;
            }
            row.push_back(1);
        }
        return row;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.getRow(3);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
