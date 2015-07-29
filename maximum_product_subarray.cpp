#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                max_product = max(max_product, product(nums, i, j));
            }
        }
        return max_product;
    }

    int product(vector<int>& nums, int i, int j) {
        int result = 1;
        for (int k = i; k <= j; k++)
            result *= nums[k];
        return result;
    }
};

int main() {

    return 0;
}
