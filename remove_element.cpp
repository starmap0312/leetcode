#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int i = -1, j = nums.size();
        i = nextI(nums, i, val);
        j = nextJ(nums, j, val);
        while (i < j) {
            swap(nums[i], nums[j]);
            i = nextI(nums, i, val);
            j = nextJ(nums, j, val);
        }
        int k;
        for (k = 0; k < nums.size(); k++)
            if (nums[k] == val) break;
        return k;
    }
    int nextI(vector<int>& nums, int i, int val) {
        int j;
        for (j = i + 1; j < nums.size(); j++)
            if (nums[j] == val) break;
        return j;
    }
    int nextJ(vector<int>& nums, int j, int val) {
        int i;
        for (i = j - 1; i >= 0; i--)
            if (nums[i] != val) break;
        return i;
    }
};

int main() {
    vector<int> nums; int val = 3;
    nums.push_back(2);
    Solution solution;
    cout << solution.removeElement(nums, val) << endl;
    return 0;
}
