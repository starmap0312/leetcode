#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        while (num != 1) {
            if (num % 2 == 0) num /= 2;
            else if (num % 3 == 0) num /= 3;
            else if (num % 5 == 0) num /= 5;
            else break;
        }
        return (num == 1);
    }
};

int main() {
    Solution solution;
    cout << solution.isUgly(6) << endl;
    cout << solution.isUgly(8) << endl;
    cout << solution.isUgly(14) << endl;
    return 0;
}
