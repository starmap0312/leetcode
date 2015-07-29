#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for (i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                break;
            } else digits[i] = 0;
        }
        if (i == -1) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution solution;
    int a[] = { 9, 9, 9, 9 };
    vector<int> digits(a, a + 4);
    vector<int> result = solution.plusOne(digits);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
