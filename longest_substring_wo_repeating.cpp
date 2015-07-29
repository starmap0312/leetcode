/* - const int *ptr; ==> ptr points to a const int (pointed object is immutable)
 * - void func(const int a); ==> pass by value, and a is immutable
 * - const int func(); ==> const int rc = func(), the return value is immutable
 * - void func() const; ==> member method func() cannot modify its class fields (like getting method)
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
private:
    int lengthOfLongestSubstringEndingAt(const string &s, int index);
    bool isRepeated(const string &s, char c, int start, int end);
};

int Solution::lengthOfLongestSubstring(string s) {
    int max_length = 0;
    for(int i = 0; i < s.size(); i++) {
        int length = lengthOfLongestSubstringEndingAt(s, i);
        if(max_length < length) max_length = length;
    }
    return max_length;
}

int Solution::lengthOfLongestSubstringEndingAt(const string &s, int index) {
    int i;
    for(i = index - 1; i >= 0; i--) {
        if(isRepeated(s, s[i], i + 1, index)) break;
    }
    return index - i;
}

bool Solution::isRepeated(const string &s, char c, int start, int end) {
    for(int i = start; i <= end; i++)
        if(c == s[i]) return true;
    return false;
}

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
