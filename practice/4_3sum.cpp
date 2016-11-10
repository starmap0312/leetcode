/* - illustration
 *
 *       c_i
 *   |--------|
 *   |--|--|--|--|--|
 *   b2 b1   a1 a2 a3
 *
 *   b_k     a_j
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& A, vector<int>& B, vector<int>& C) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<vector<int> > result;
        for (int i = 0; i < C.size(); i++) {
            int c = C[i];
            int j = 0, k = B.size() - 1;
            while (j < A.size() && k >= 0) {
                int a = A[j], b = B[k];
                if (a + b < c) j++;
                else if (a + b > c) k--;
                else { // a + b == c
                    vector<int> solution;
                    solution.push_back(a), solution.push_back(b), solution.push_back(c);
                    result.push_back(solution);
                    j++;
                }
            }
        }
        return result;
    }
};

int main() {
    int a[6] = { -1, 0, 1, 2, -1, -4 };
    vector<int> A(a, a + 6), B(a, a + 6), C(a, a + 6);
    Solution solution;
    vector<vector<int> > result = solution.threeSum(A, B, C);
    for (int i = 0; i < result.size(); i++){
        cout << result[i][0] << " + " << result[i][1] <<" = " << result[i][2] << endl;
    }
    return 0;
}
