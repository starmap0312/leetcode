/* 1          2       3         4
 * 1          1     1*2     1*2*3  ==> result[0...3]
 * *2*3*4  *3*4      *4            ==> result[0...3]
 * to summarize, frist scan the input array from left to right, computing at each position
 * the product of all the numbers to the left of that position
 * next, scan the input array from right to left and computing at each position the product
 * of all the numbers to the left of that position
 * the two results are multiplied and stored in the output vector
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int product = 1;
        result.push_back(product);
        for (int i = 0; i < nums.size() - 1; i++) {
            product *= nums[i];
            result.push_back(product);
        }
        product = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            product *= nums[i];
            result[i - 1] *= product;
        }
        return result;
    }
};

int main() {
    int a[] = { 1, 2, 3, 4 };
    vector<int> nums(a, a + 4);
    Solution solution;
    vector<int> rc = solution.productExceptSelf(nums);
    for (int i = 0; i < rc.size(); i++)
        cout << rc[i] << " ";
    cout << endl;
    return 0;
}
