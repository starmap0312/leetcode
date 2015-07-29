/* 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) return true;
        return false;
    }
};

int main() {
    //int a[4] = { 1, 3, 1, 1 }; 
    //vector<int> nums(a, a + 4);
    int a[16] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; 
    vector<int> nums(a, a + 16);
    Solution solution;
    cout << solution.search(nums, 2) << endl;
    return 0;
}
