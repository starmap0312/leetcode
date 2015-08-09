#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return x;
        double sum = 1.0;
        for (int i = 0; i < n; i++)
            sum = sum * x;
        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(3.0, 3) << endl;
    return 0;
}
