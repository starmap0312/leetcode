#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() > 0) {
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i++)
                if (nums[i - 1] == nums[i]) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}
