#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int size = 1, prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[size] = nums[i];
                size++;
                prev = nums[i];
            }
        }
        return size;
    }
};

int main() {

    return 0;
}
