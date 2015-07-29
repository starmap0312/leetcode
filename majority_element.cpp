#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for (unordered_map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++)
            if (itr -> second > nums.size() / 2) return itr -> first;
        return 0;
    }
};

int main() {
    int a[] = { 1, 2, 2, 1, 3, 8, 1, 1, 1, 1, 2, 1 };
    vector<int> nums(a, a + 12);
    Solution solution;
    cout << solution.majorityElement(nums) << endl;
    return 0;
}
