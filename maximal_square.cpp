#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        int max_area = 0;
        vector<int> square(matrix[0].size(), 0), extension(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            int left_ext = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    if (j == 0) square[j] = 1;
                    else square[j] = min(left_ext, min(square[j], extension[j])) + 1;
                    max_area = max(max_area, square[j]);
                    extension[j] += 1;
                    left_ext += 1;
                } else {
                    if (j == 0) square[j] = 0;
                    else square[j] = 0;
                    extension[j] = 0;
                    left_ext = 0;
                }
            }
            for (int j = matrix[i].size() - 1; j >= 1; j--) square[j] = square[j - 1];
        }
        return max_area * max_area;
    }
};

int main() {
    return 0;
}
