#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int extension = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > extension) break;
            extension = max(extension, i + nums[i]);
        }
        return (extension >= nums.size() - 1);
    }
};

int main() {
    Solution solution;
    int a[5] = { 2, 3, 1, 1, 4 };
    vector<int> v(a, a + 5);
    cout << solution.canJump(v) << endl;
    return 0;
}
