#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i > j) return 0;
        if (i == 0) return prefixSum[j];
        return prefixSum[j] - prefixSum[i - 1];
    }

private:
    vector<int> prefixSum;
};

int main() {
    int a[] = { -2, 0, 3, -5, 2, -1 };
    vector<int> nums(a, a + 6);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
