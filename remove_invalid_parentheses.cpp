/* - exhaust all possibilities of the removal of parentheses
 *   use branch and bound to improve the time complexity
 *   specifically, start from removing 0 parenthesis to remove more parentheses
 *   for each number of removal, exhaust all possible choices of the removed parentheses via 
 *   recursion
 * - note that once the choice of removed parentheses already leads to invalid sentence, return
 *   from the recursion immediately:
 *   ex. the number of ')' read so far is greater than the number of '(' read
 *       the number of '(' read so far is greater than the number of ')' not yet read 
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        for (int numRemoval = 0; numRemoval < s.size(); numRemoval++) {
            set<int> removal;
            solve(s, removal, 0, numRemoval);
            if (answer.size() != 0) {
                return vector<string>(answer.begin(), answer.end());
            }
        }
        return vector<string>(1, removeParentheses(s));
    }

    string removeParentheses(string &s) {
        string result = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '(' && s[i] != ')')
                result += s[i];
        return result;
    }

    void solve(string &s, set<int> &removal, int index, int numRemoval) {
        if (numRemoval == 0) {
            if (isValid(s, removal))
                answer.insert(createString(s, removal));
            return;
        }
        if (!isPartiallyValid(s, removal, index)) return;
        for (int i = index; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                removal.insert(i);
                solve(s, removal, i + 1, numRemoval - 1);
                removal.erase(i);
            }
        }
    }

    string createString(string &s, set<int> &removal) {
        string result = "";
        for (int i = 0; i < s.size(); i++)
            if (removal.find(i) == removal.end())
                result += s[i];
        return result;
    }

    bool isPartiallyValid(string &s, set<int> &removal, int index) {
        int num = 0;
        for (int i = 0; i < index; i++) {
            if (removal.find(i) != removal.end()) continue;
            if (s[i] == '(') num++;
            else if (s[i] == ')') num--;
            if (num < 0) return false;
        }
        int remaining = 0;
        for (int i = index; i < s.size(); i++)
            if (s[i] == ')') remaining++;
        if (num > remaining) return false;
        return true;
    }

    bool isValid(string &s, set<int> &removal) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (removal.find(i) != removal.end()) continue;
            if (s[i] == '(') num++;
            else if (s[i] == ')') num--;
            if (num < 0) return false;
        }
        if (num != 0) return false;
        return true;
    }

private:
    set<string> answer;
};

int main() {
    Solution solution;
    vector<string> rc = solution.removeInvalidParentheses("((z(((fp))()((((((g(");
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << endl;
    return 0;
}
