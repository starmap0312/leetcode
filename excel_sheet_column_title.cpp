#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string results = "";
        while(n != 0) {
            int quotient = n / 26, remainder = n % 26;
            if (remainder == 0) { quotient--; remainder = 26; }
            results = (char) ('A' - 1 + remainder) + results;
            n = quotient;
        }
        return results;
    }
};

int main() {
    Solution solution;
    cout << solution.convertToTitle(27) << endl;
    return 0;
}
