/* - when subtracting size, eg. vector v; v.size() or string s; s.size(), remember to explicitly
 *   convert the type into signed int, otherwise negative value will underflow to large positive
 * - C function strstr() of string.h ==> char s[] = "a simple string"; 
 *   char * ptr = strstr(s, "simple") is the first matched char * pointer of the occurrence,
 *   if there is no matched occurrence, the function returns NULL
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0) return 0;
        int i;
        for (i = 0; i <= (int)haystack.size() - (int)needle.size(); i++)
            if (haystack.substr(i, needle.size()) == needle) break;
        return (i > (int)haystack.size() - (int)needle.size()? -1: i);
    }
};

int main() {
    string haystack = "This is a simple string";
    string needle = "simple";
    Solution solution;
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}
