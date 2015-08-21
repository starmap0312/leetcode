/* - use recursion to find all possible partitions: [1-3][1-3][1-3][1-3]
 *   check validation when all partition are determined
 * - string s = "12345"; to remove the last char of s ==> s.substr(0, s.size() - 1);
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> choices;
        choose(s, choices, 4, s.size());
        return result;
    }
    void choose(string &s, vector<int> &choices, int numFields, int numDigits) {
        if (numFields > numDigits || 3 * numFields < numDigits) return;
        if (numFields == 0 && numDigits == 0) {
            string ip = "";
            int index = 0;
            for (int i = 0; i < choices.size(); i++) {
                string field = s.substr(index, choices[i]);
                if (field[0] == '0' && field.size() > 1) return;
                if (atoi(field.c_str()) > 255) return;
                ip = ip + field + ".";
                index += choices[i];
            }
            result.push_back(ip.substr(0, ip.size() - 1));
            return;
        }
        for (int i = 1; i <= 3; i++) {
            choices.push_back(i);
            choose(s, choices, numFields - 1, numDigits - i);
            choices.pop_back();
        }
    }
private:
    vector<string> result;
};

int main() {
    Solution solution;
    vector<string> result = solution.restoreIpAddresses("25525511135");
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
