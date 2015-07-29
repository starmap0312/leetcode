/* - set<int> s; ==> use s.insert(3) to insert element 3, and s.erase(3) to delete 
 *                   element 3, or use s.erase(itr) to delete element pointed by 
 *                   set<int>::iterator itr
 *                   to traverse set s, use the following:
 *                   for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++)
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> dict;
        for (int i = 0; i < nums.size(); i++) {
            set<int>::iterator itr = dict.find(nums[i]);
            if (itr == dict.end()) dict.insert(nums[i]);
            else dict.erase(itr);
        }
        return (dict.size() == 1? *dict.begin(): -1);
    }
};

int main() {
    int a[4] = { 1, 2, 4, 3 };
    vector<int> nums(a, a + 4);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
