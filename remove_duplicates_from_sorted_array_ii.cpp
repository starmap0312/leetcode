#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int size = 1, prev = nums[0];
        bool twice = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[size++] = nums[i];
                prev = nums[i];
                twice = false;
            } else if (nums[i] == prev && !twice) {
                nums[size++] = nums[i];
                twice = true;
            }
        }
        return size;
    }
};

int main() {
    int a[6] = {1,1,1,2,2,3};
    vector<int> nums(a, a + 6);
    Solution solution;
    int size = solution.removeDuplicates(nums);
    for (int i = 0; i < size; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
