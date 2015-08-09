#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool hasRowZero = false;
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                hasRowZero = true;
                break;
            }
        }
        bool hasColumnZero = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                hasColumnZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] != 0) continue;
            for (int i = 1; i < matrix.size(); i++)
                matrix[i][j] = 0;
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] != 0) continue;
            for (int j = 1; j < matrix[i].size(); j++)
                matrix[i][j] = 0;
        }
        if (hasRowZero) {
            for (int j = 1; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        if (hasColumnZero) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
        if (hasRowZero) matrix[0][0] = 0;
    }
};

int main() {

    return 0;
}
