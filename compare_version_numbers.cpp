/* - string s; ==> s.find('a', 3) to find if char 'a' appears in the substring of s starting from index 3
 *                 s.find("abc", 3) to find if string "abc" appears in the substring of s starting from index 3
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1 = split(version1);
        vector<int> nums2 = split(version2);
        return compare(nums1, nums2);
    }
    int compare(vector<int> &nums1, vector<int> &nums2) {
        for (int i = 0; i < max(nums1.size(), nums2.size()); i++) {
            int n1 = (i < nums1.size()? nums1[i]: 0);
            int n2 = (i < nums2.size()? nums2[i]: 0);
            if (n1 > n2) return 1;
            else if (n1 < n2) return -1;
        }
        return 0;
    }
    vector<int> split(string version) {
        vector<int> nums;
        int pos = 0;
        while (pos < version.size()) {
            int nextPos = version.find('.', pos);
            if (nextPos == string::npos) {
                nums.push_back(atoi(version.substr(pos).c_str()));
                break;
            } else
                nums.push_back(atoi(version.substr(pos, nextPos - pos).c_str()));
            pos = nextPos + 1;
       }
       return nums;
    }
};

int main() {
    Solution solution;
    cout << solution.compareVersion("1.0", "1.1") << endl;
    return 0;
}
