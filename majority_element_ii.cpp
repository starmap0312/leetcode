#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        vector<int> result;
        for (unordered_map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++)
            if (itr -> second > nums.size() / 3) result.push_back(itr -> first);
        return result;
    }
};

int main() {
    int a[] = { 1, 2, 2, 1, 3, 8, 1, 1, 4, 3, 2, 1 };
    vector<int> nums(a, a + 12);
    Solution solution;
    vector<int> result = solution.majorityElement(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
