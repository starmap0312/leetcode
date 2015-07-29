/* - to initialize a vector of 5 empty strings ==> use vector<string> s(5, "");
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rowString(numRows, "");
        for (int i = 0; i < s.size(); i++)
            rowString[convertIndex(i, numRows)] += s[i];
        string result = "";
        for (int i = 0; i < rowString.size(); i++)
            result += rowString[i];
        return result;
    }
    int convertIndex(int i, int numRows) {
        int remainder = i % (2 * numRows - 2);
        if (remainder < numRows) return remainder;
        else return (2 * numRows - 2 - remainder);
    }
};

int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
