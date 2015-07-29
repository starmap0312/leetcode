/* - vector<int> nums; ==> sort(nums.begin(), nums.end(), func); sorts vector nums based on the
 *                         comparing function func, where bool func(int a, int b) should return
 *                         if (a < b) ? (ascending order, to reverse, func() should return if (a > b)?
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string &s1, string &s2) {
    string leftRight = s1 + s2, rightLeft = s2 + s1;
    if (leftRight > rightLeft) return true;
    else return false;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStrings = toString(nums);
        sort(numStrings.begin(), numStrings.end(), compare);
        return eraseZeroPrefix(concatenate(numStrings));
    }
    vector<string> toString(vector<int> &nums) {
        vector<string> result;
        for (int i = 0; i < nums.size(); i++) result.push_back(to_string(nums[i]));
        return result;
    }
    string concatenate(vector<string> & numStrings) {
        string result = "";
        for (int i = 0; i < numStrings.size(); i++) result += numStrings[i];
        return result;
    }
    string eraseZeroPrefix(string s) {
        int i;
        for (i = 0; i < s.size(); i++)
            if (s[i] != '0') break;
        return (i >= s.size()? "0": s.substr(i));
    }
};

int main() {
    Solution solution;
    const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> nums(a, a + 10);
    cout << solution.largestNumber(nums) << endl;
    return 0;
}
